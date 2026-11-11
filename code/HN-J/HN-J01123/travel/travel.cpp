#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,ans;
char s,t;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>x>>s>>m>>y>>t;
	if(n==m){
		ans++;
		ans*=10;
		if(x==y){
			ans++;
			ans*=10;
			if((s<'D'&&t<'D')||(s>='D'&&t>='D')){
				ans++;
				ans*=10;
				if(s-t==1||t-s==1)ans++;
			}else ans*=10;
		}else ans*=100;
		cout<<ans;
	}else cout<<"0000";
	return 0;
}
