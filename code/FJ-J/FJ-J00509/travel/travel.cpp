#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
string s1,s2;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>n>>s1>>m>>s2;
	if(s1[2]=='F') s1[2]='E';
	if(s2[2]=='F') s2[2]='E';
	if(n==m){
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			if(s1[2]<'D'&&s2[2]<'D'||s1[2]>='D'&&s2[2]>='D'){
				if(abs(s1[2]-s2[2])==1) cout<<1111;
				else cout<<1110;
			}else cout<<1100;
		}else cout<<1000;
	}else cout<<"0000";
	return 0;
}
