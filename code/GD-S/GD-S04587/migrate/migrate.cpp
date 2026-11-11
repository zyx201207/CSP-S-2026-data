#include<bits/stdc++.h>
using namespace std;
int n,x[2000005],c,T,ans=0,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			ans+=x[i];
		}
		cout<<abs(ans);
	}
}s
