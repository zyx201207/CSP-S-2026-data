#include <bits/stdc++.h>

using namespace std;

string c1,s1,c2,s2;
bool a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1==c2) a=1;
	if (a && s1[0]==s2[0] && s1[1]==s2[1]) b=1;
	if (b && s1[2]>='A' && s1[2]<='C' && s2[2]>='A' && s2[2]<='C') c=1;
	if (b && s1[2]>='D' && s1[2]<='F' && s2[2]>='D' && s2[2]<='F') c=1;
	if (c && abs(s1[2]-s2[2]<=1)) d=1;
	if (a) cout << 1;
	else cout << 0;
	if (b) cout << 1;
	else cout << 0;
	if (c) cout << 1;
	else cout << 0;
	if (d) cout << 1;
	else cout << 0;
	return 0;
}