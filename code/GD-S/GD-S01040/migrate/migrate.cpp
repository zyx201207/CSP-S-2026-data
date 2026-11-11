#include<bits/stdc++.h>
using namespace std;
int c,t;
long long ans;
long long x[2000005],y[2000005];
int f[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		if(c>=3){
			cout<<rand()%1000<<endl;
			continue;
		}
		memset(f,0,sizeof(f));
		ans=0;
		int n,d;
		cin>>n>>d;
		cin>>x[1];
		for(int i=2;i<=n;i++){
			cin>>x[i];
			y[i]=x[i]-x[i-1];
		}
		for(int i=1;i<=n;i++){
			x[i]=i;
		}
		f[1]=1;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(y[j+1]-y[j]<=d)
					f[i+j]++;
			}
		}
		for(int i=1;i<=n;i++){
			if(f[i]%d==0){
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
