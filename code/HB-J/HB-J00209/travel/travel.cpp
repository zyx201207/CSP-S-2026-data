#include <bits/stdc++.h>
using namespace std;
string rc,rz,xc,xz;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> rc >> rz >> xc >> xz;
	if(rc==xc) cout << 1;
	else cout << 0;
	if(rc==xc&&rz[0]==xz[0]&&rz[1]==xz[1]) cout << 1;
	else cout << 0;
	if(rc==xc&&rz[0]==xz[0]&&rz[1]==xz[1]&&((rz[2]=='A'&&xz[2]=='B')||
	(rz[2]=='B'&&xz[2]=='A')||(rz[2]=='A'&&xz[2]=='C')||(rz[2]=='C'&&xz[2]=='A')
	||(rz[2]=='B'&&xz[2]=='C')||(rz[2]=='C'&&xz[2]=='B')||(rz[2]=='D'&&xz[2]=='F')
	||(rz[2]=='F'&&xz[2]=='D'))) cout << 1;
	else cout << 0;
	if(rc==xc&&rz[0]==xz[0]&&rz[1]==xz[1]&&((rz[2]=='A'&&xz[2]=='B')||
	(rz[2]=='B'&&xz[2]=='A')||(rz[2]=='B'&&xz[2]=='C')||
	(rz[2]=='C'&&xz[2]=='B')||(rz[2]=='D'&&xz[2]=='F')
	||(rz[2]=='F'&&xz[2]=='D'))) cout << 1;
	else cout << 0;
	return 0;
}
