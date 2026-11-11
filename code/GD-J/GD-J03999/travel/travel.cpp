#include <fstream>
#include <string>
#include <iostream>

struct ticket {
	int tid, row;
       	char col;
};

ticket parse(int c, std::string s) {
	ticket t;
	t.tid = c;
	t.row = static_cast<int>(s[0] - '0') * 10 + static_cast<int>(s[1] - '0');
	t.col = s[2] + (s[2] == 'D');
	return t;
}	

int main() {
	std::ifstream in("travel.in");
	std::ofstream out("travel.out");
	int c1, c2;
	std::string s1, s2;
	in >> c1 >> s1 >> c2 >> s2;
	auto t1 = parse(c1, s1);
	auto t2 = parse(c2, s2);
	out << (t1.tid == t2.tid)
	    << (t1.tid == t2.tid && t1.row == t2.row) 
	    << (t1.tid == t2.tid && t1.row == t2.row && ((t1.col <= 'C' && t2.col <= 'C') || (t1.col > 'C' && t2.col > 'C')))
	    << (t1.tid == t2.tid && t1.row == t2.row && (t1.col == t2.col + 1 || t1.col == t2.col - 1));
}
