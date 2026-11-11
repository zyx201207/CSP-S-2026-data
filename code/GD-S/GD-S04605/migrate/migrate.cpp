#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,ans;
long long x[2000006],vis[2000006];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>c>>t;
	if(c==11||c==12){
		while(t--){ans=0;
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>x[i];
			}
			if(n<3)cout<<"0\n"; 
			else if(x[3]-x[1]>d)cout<<"0\n";
			else{
				long long a=x[2]-x[1];
				d=d/a;
				long long b=min(d*2,n);
				for(int i=d+1;i<=b;i++){
					ans+=(n-i);
				}
				cout<<ans<<"\n";
			}
		}
	}else{
		while(t--){ans=0;
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>x[i];
				if(x[i]-x[i-1]<=d)vis[i]=1;
				vis[1]=1;
				vis[i]+=vis[i-1];
			}
			for(int i=1;i<=n;i++){
				for(int j=1;j<i;j++){
					if(x[i]-x[j]>d&&x[i]-x[j]<2*d&&vis[i]-vis[j]==i-j){
						ans++;
					}
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
} 
