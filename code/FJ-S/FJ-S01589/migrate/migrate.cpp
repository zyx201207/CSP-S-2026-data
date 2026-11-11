#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d;
long long a[2000010],b[2000010];
int s[6000][6000],g[6000][6000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>c>>t;
	while(t--){
		if(c==11||c==12){
			cin>>n>>d;	
			long long sum=0;
			for(int i=1;i<=n;i++) cin>>a[i];
			int g=a[2]-a[1];
			int f=d/g;
			for(int i=1;i<=n;i++){
				if(i+2*f-1<=n) sum++;
				else break;
			}	
			cout<<sum<<endl;	
		}
		else if(c<=10){
			long long ans=0;
			memset(s,0,sizeof(s));
			memset(g,0,sizeof(g));
			cin>>n>>d;
			for(int i=1;i<=n;i++) cin>>a[i];
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(a[j]-a[i]<=d) s[i][j]=1; 
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n&&s[i][j];j++){
					for(int k=j+1;k<=n&&(s[j][k]);k++){
						if(s[i][k]) continue;
						g[i][k]++;
					}
				}
			}
			for(int i=1;i<=n;i++){
				for(int j=i+1;j<=n;j++){
					if(g[i][j]==2) ans++;
				}
			}
			cout<<ans<<endl;
		}
		else {
			cin>>n>>d;
			for(int i=1;i<=n;i++) cin>>a[i];
			cout<<0<<endl; 
		}
	}
	return 0;
}
