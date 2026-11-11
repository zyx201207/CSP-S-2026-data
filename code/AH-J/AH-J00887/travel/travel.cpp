#include <bits/stdc++.h>
using namespace std;
using ll=long long;
string c1,s1,c2,s2;
char a,b;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	a=s1[2],b=s2[2];
	s1.pop_back(),s2.pop_back();
	cout<<(c1==c2)<<(s1==s2 && c1==c2)<<(((a<'D' && b<'D') || (a>'C' && b>'C')) && s1==s2 && c1==c2)<<(c1==c2 && s1==s2 && ((a<'D' && b<'D') || (a>'C' && b>'C')) && ((a=='A' && b=='B') || (a=='B' && b<'D') || (a=='C' && b=='B') || (a>'C' && b>'C')));
	return 0;
}
