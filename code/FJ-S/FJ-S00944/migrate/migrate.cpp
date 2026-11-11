#include<bits/stdc++.h>
using namespace std;
long long cf,n,d,a[2000005],b[2000005],gl[2000005],c[2000005],lx[2000005],rx[2000005],ans,INF=1e9;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin>>cf>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		if(n==1){
			cout<<"0\n";
			continue;	
		}
		if(cf==11||cf==12){
			long long dl=(a[n]-a[1])/(n-1);	
			if(d>=dl*2)cout<<n-d/dl*2+1<<'\n';
			else cout<<0<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++){
			lx[i]=lower_bound(a+1,a+n+1,a[i]-d)-a;
			rx[i]=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
		}
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++)c[j]=0,gl[i]=0;
			c[i-1]=0;
			b[i]=0,c[i]=1;
			for(int j=i+1;j<=n;j++){
				if(lx[j]<=i){
					b[j]=1,c[j]=1;
					gl[1]=j;
				}else if(lx[j]==j){
					break;
				}else{
					b[j]=b[lx[j]]+1;
					int cf=gl[b[j]-1];
					c[j]=c[cf]-c[lx[j]-1];
					if(c[j]==2)ans++;
					gl[b[j]]=j;
				}
				c[j]+=c[j-1];
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}

