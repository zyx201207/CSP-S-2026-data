// GZ-S00350 王陈扬 遵义市第三十中学
#include <bits/stdc++.h>
using namespace std;

struct Cross{
	int a;
	int b;
};

struct CrossPlan {
    vector< vector<Cross> > crosses;
    bool needMore = false;
};

vector<CrossPlan> get_cross(
                            vector < pair<int, int> > line,
                            vector < pair<int, int> > linet,
                            int pi,
                            int bi,
                            vector<CrossPlan> crossplan
                            );

vector<CrossPlan> get_cross_more(
                                vector < vector< pair<int, int> > > k,
                                int pi,
                                int bi,
                                vector<CrossPlan> crossplan
                                ) {
    vector< pair<int, int> > pik = k[pi];
    vector<CrossPlan> tmpcp;
    for (int i = pi + 1; i < k.size(); i++) {
        tmpcp = get_cross(pik, k[i], pi, pi + 1, crossplan);
        if (tmpcp [tmpcp.size() - 1].needMore) {
            tmpcp.pop_back();
        }
    }
    return tmpcp;
}

vector<CrossPlan> get_cross(
                            vector < pair<int, int> > line,
                            vector < pair<int, int> > linet,
                            int pi,
                            int bi,
                            vector<CrossPlan> crossplan
                            ) {
	// returns cross stations
	vector<Cross> crosses;
	for (int i = 0; i < line.size(); i++) {
		pair<int, int> p = line[i];
		for (int j = 0; j < linet.size(); j++) {
			pair<int, int> sp = linet[j];
			if (p.first == sp.first) {
				Cross ncross;
				ncross.a = i;
				ncross.b = j;
				crosses.push_back(ncross);
			}
		}
	}
	CrossPlan ncp;
	ncp.crosses.push_back(crosses);
	if (crosses.size() == 0) {
        // !!! NEED MIDDLE STATION.
        ncp.needMore = true;
	}
	crossplan.push_back(ncp);
	return crossplan;
}

int try_for(int pw,
			int qw,
			Cross cross,
			vector< pair<int, int> > k,
			vector< pair<int, int> > dk
			) {
	int time, nlim;
	time += pw + qw;
	/*
	for (int i = 0; i < 100; i ++) {
		nlim = nlims [i];
		for (int j = 0; j < 100; j ++) {

		}
	} */
	int a = cross.a, b = cross.b;
	time += dk [a].second + dk [b].second;
	time += k [a].second + k [b].second;
	return time;
}

int main() {
	// ifstream in("subway.in");
	// ofstream out("subway.out");
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
	int c, n, m, d, q;
	// c: ign, n: line c., m: station c., d: max cross l., q: plans.
	cin >> c >> n >> m >> d >> q;
	int w[m]; // station -> export time
	for (int i = 0; i < m; i++)
        cin >> w[i];

	// int k[m];
	// int dk[d];
	vector< vector< pair<int, int> > > k;

	int nlim;
	for (int i = 0; i < n; i++) {
		cin >> nlim;
		vector< pair<int, int> > nk;
		for (int j = 0; j < nlim; j++) {
			int ki, dkd;
			cin >> ki >> dkd;
			pair<int, int> nkp;
			nkp.first = ki;
			nkp.second = dkd;
			nk.push_back(nkp);
		}
		k.push_back(nk);
	}

	int p[q]; // start p
	int b[q]; // end b

	for (int i = 0; i < q; i++) {
		cin >> p[i] >> b[i];
	}

	int time = 999999;
	vector<CrossPlan> crosses;
	for (int i = 0; i < q; i++) {
		int pi = p [i], bi = b [i];
		crosses = get_cross_more(k, pi, bi, crosses);
		for (int j = 0; j < crosses.size(); j++) {
            for (int z = 0; z < crosses[j].crosses.size(); z ++) {
                time = min(time, try_for(w[pi], w[bi], crosses[j].crosses[z], k [pi - 1], k [bi - 1]);
            }
		}
		cout << time << "\n";
	}

	/* 90	55	C:\Users\Administrator.T8I0XSZAI6AFIOC\Desktop\GZ-S00350\subway\subway.cpp	[Error] could not convert 'k.std::vector<_Tp, _Alloc>::operator[]<std::vector<std::pair<int, int> >, std::allocator<std::vector<std::pair<int, int> > > >(((std::vector<std::vector<std::pair<int, int> > >::size_type)pi))' from 'std::vector<std::pair<int, int> >' to 'Cross' */

	return 0;
}
