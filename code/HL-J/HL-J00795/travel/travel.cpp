#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve(){
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	cout<<(c1==c2?1:0);
	cout<<(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]?1:0);
	cout<<(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&(((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')
	&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))
	||((s1[2]=='D'||s1[2]=='E')&&(s2[2]=='D'||s2[2]=='E')))?1:0);
	cout<<(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&
	(((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')
	&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))
	||((s1[2]=='D'||s1[2]=='E')&&(s2[2]=='D'||s2[2]=='E')))&&
	abs(s1[2]-s2[2])==1?1:0);
}
#undef int
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
//	int t;
//	cin>>t;
//	while(t--){
		solve();
//	}
	return 0;
}
