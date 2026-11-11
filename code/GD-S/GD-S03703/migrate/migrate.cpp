#include<bits/stdc++.h>
using namespace std;
int c,t,n,num;
long long d,x[2000005],ans[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	for(int y=1;y<=t;++y){
		num=0;
		cin>>n>>d;
		for(int i=1;i<=n;++i)cin>>x[i];
		for(int i=1;i<=n-2;++i){
			if(x[i+1]-x[i]!=x[i+2]-x[i+1])num=1;
		}
		if(n<=2){
			ans[y]=0;
			continue;
		}
		if(num==0){
			long long a=x[2]-x[1];
			if(d/a<2){
				ans[y]=0;
				continue;
			}
			ans[y]=n-2*(d/a+1)+3;
			if(ans[y]<0)ans[y]=0;
			continue;
		}
		ans[y]=0;
	}
	for(int i=1;i<=t;++i)cout<<ans[i]<<"\n";
	return 0;
} 
