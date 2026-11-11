#include<bits/stdc++.h>
using namespace std;
int c,T;
int n;
long long d; 
long long x[2000010],g[200010];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		long long ans=0;
		for(int i=1;i<=n;i++){
			cin>>x[i];
			g[i]=x[i]-x[i-1];
		}
		sort(g+2,g+1+n);
		if(g[2]==g[n]){//A
			for(int i=1;i<n;i++){
				for(int j=i+2;j<=n;j++){
					if((j-i)%d==0){
						continue;
					}
					int len=j-i;
					if(len==d*2-1){
						ans++;
					}
					
				}
			}
			cout<<ans<<endl;
			continue;
		}else if(x[n]-x[1]<=2*d){
			for(int i=1;i<n;i++){
				for(int j=i+2;j<=n;j++){
					if(x[j]-x[i]<=d){
						continue;
					}else{
						if(j==i+3 and x[i+1]-x[i]<=d and x[j]-x[j-2]<=d and x[i+2]-x[i]<=d and x[j]-x[j-1]<=d){
							ans++;
						}
					}
				}
			}
			cout<<ans<<endl;
			continue;
		}else{
			cout<<1<<endl;
		}
	}
	return 0;
} 
