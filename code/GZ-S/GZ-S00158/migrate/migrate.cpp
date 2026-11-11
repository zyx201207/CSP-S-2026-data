//GZ-S00158 贵阳市第三中学 李书涵
#include<bits/stdc++.h>
using namespace std;
const int N=2*1e6+10;
int c,t,n,d;
int x[N],ans[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		int ans=n;
		for(int i=1;i<=n;i++){
			if(x[i]+d<x[i+1] || n-i<3)ans--;
		}
		cout<<ans<<endl;
	}
	
	return 0;
}
