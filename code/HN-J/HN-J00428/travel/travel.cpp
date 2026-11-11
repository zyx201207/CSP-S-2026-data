#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n=4;
string c1,s1,c2,s2;
void solve(){
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		n--;
		if(s1[0]==s2[0]&&s2[1]==s1[1]){
			cout<<1;
			n--;
			if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')){
				cout<<1;
				n--;
				if(char(s1[2]+1)==s2[2]||char(s1[2]-1)==s2[2]){
					cout<<1;
					n--;
				}
			}
			if((s1[2]=='F'||s1[2]=='D')&&(s2[2]=='F'||s2[2]=='D')){
				cout<<1;
				n--;
				if(char(s1[2]+1)==s2[2]||char(s1[2]-1)==s2[2]){
					cout<<1;
					n--;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<0;
	}
	return ;
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T=1;
//	cin>>T;
	while(T--){
		solve();
	}
	return 0;
}
