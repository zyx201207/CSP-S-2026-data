#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,v,a[2000010],b[2000010],sum,cnt,mn=0x3f3f3f3f3f3f3f3f;
void dt(long long u,long long ans){
	if(u==v){
		if(ans==mn) cnt++;
		if(ans<mn){
			mn=ans;
			cnt=1;
		}
		return ;
	}
	for(int i=u+1;i<=min(n,b[u]);i++){
		dt(i,ans+1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		memset(b,0,sizeof(b));
		sum=0;
		scanf("%lld %lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d){
					b[i]=j;
				}
				else{
					break;
				}
			}
			if(b[i]==0) b[i]=n;
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				v=j;
				long long u=i;
				mn=0x3f3f3f3f3f3f3f3f,cnt=0;
				dt(u,0);
				if(cnt==2){
					sum++;
				}
			}
		}
		cout<<sum<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
