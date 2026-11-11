#include <iostream>
#include <tuple>
using namespace std;

#ifdef DBG
#define dbg(x) cerr<<"@@ "<<__LINE__<<" : "<<#x<<" = "<<x<<'\n';
#else
#define dbg(x)
#endif
bool isSmS(char c1, char c2) {
	if (c1 == 'D' || c2 == 'D' || c1 == 'F' || c2 == 'F') {
		return (c1 == 'D' && c2 == 'F') || (c1 == 'F' && c2 == 'D');
	}
	return true;
}
bool isNT(char c1, char c2) {
	dbg(c1);
	dbg(c2);
	dbg(c1 - c2); 
	return abs(c1 - c2) == 1;
}

void gInfo(string& seat, int& row, char& col) {
	col = seat[2];
	seat = string(seat.begin(), seat.end() - 1);
	row = stoi(seat);
}

int main() {
#ifdef DBG
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#else
	freopen("travel.in", "r", stdin); // <<<<<<<<<<<<<<<<<<<<<
	freopen("travel.out", "w", stdout);
#endif
	ios::sync_with_stdio(false);
	cin.tie(0);

	string Sc1, Ss1, Sc2, Ss2;
	cin>>Sc1>>Ss1>>Sc2>>Ss2;
	int r1, r2;
	char c1, c2;
	gInfo(Ss1, r1, c1);
	gInfo(Ss2, r2, c2);
	
	bool smC = Sc1 == Sc2;
	bool smR = smC && r1 == r2;
	bool smS = smR && isSmS(c1, c2);
	bool nt = smS && isNT(c1, c2);
	
	cout<<smC<<smR<<smS<<nt; 
	
	return 0;
} 
