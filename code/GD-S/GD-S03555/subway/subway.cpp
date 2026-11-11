#include <iostream>
#include <fstream>
#include <queue>
#include <map>
#include <set>
#include <climits>

struct Node {
	int sid, t;
	bool operator<(const Node& other) const& {
		return t < other.t;
	}
};

std::vector<int> tfe2s; // Time of from entry to station.
std::vector<std::vector<std::pair<int, int>>> tfsts; // Time of from station to subway.
std::vector<std::vector<std::pair<int, int>>> sol; // Stations on line.

namespace carryrao {
int solve(int s, int e) {
	std::priority_queue<Node> nodes;
	nodes.push(Node{s, tfe2s[s]});
	std::set<int> v; // Visited, 0x917813 + line, station.
	v.insert(s);
	while (!nodes.empty()) {
		auto now = nodes.top();
		nodes.pop();
		// std::clog << "At station" << now.sid << ": \n";
		for (auto i : tfsts[now.sid]) {
			if (v.find(0x917813 + i.first) != v.end()) {
				continue;
			}
			v.insert(0x917813 + i.first);
			for (auto j : sol[i.first]) {
				if (v.find(j.first) != v.end()) {
					continue;
				}
				int newt = now.t + i.second + j.second;
				if (j.first == e) {
					// std::clog << "\tline " << i.first << ",next station: " << j.first << ", time: " << newt + tfe2s[j.first] << ", done!" << std::endl;
					return newt + tfe2s[j.first];	
				}
				v.insert(j.first);
				// std::clog << "\tline " << i.first << ",next station: " << j.first << ", time: " << newt << std::endl;
				nodes.push(Node{j.first, newt});
			}
		}
	}
	return INT_MAX;
}
}

int main() {
	std::ifstream in("subway.in");
	std::ofstream out("subway.out");

	int n, m, d, q; // n: totel lines, m: totel stations, d: max lines of each station, q: plans.
	in >> n >> n >> m >> d >> q;
	tfe2s.reserve(m);
	for (int i = 1; i <= m; ++i) {
		int t;
		in >> t;
		tfe2s.push_back(t);
	}
	tfsts.reserve(m + 1);
	sol.reserve(n + 1);
	for (int i = 1; i <= n; ++i) {
		int n;
		in >> n;
		for (int j = 1; j <= n; ++j) {
			int a, t;
			in >> a >> t;
			tfsts[a].push_back({i, t});
			sol[i].push_back({a, t});
		}
	}
	for (int i = 1; i <= q; ++i) {
		int s, e;
		in >> s >> e;
		out << carryrao::solve(s, e) << std::endl;
	}	

}

// Giving me up!
// I'm only a mudium school child, how did I get into the second competition???
// Uh, It's so difficult.
// I don't want to debug it now, because the dataset is too large...
