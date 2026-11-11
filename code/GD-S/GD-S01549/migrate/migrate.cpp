#include<bits/stdc++.h>
using namespace std;
#define int long long
long long x[1000100],a[5100][5100],p[1000010];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for (int i=1;i<=n;i++){
			cin>>x[i];
		}
		for (int i=1;i<=n-1;i++){
			a[i][i+1]=1;
		} 
		long long ans=0;
		for(int i=1;i<=n;i++){
			int lst=i,minn=1;
			for (int j=i+1;j<=n;j++){
				if(p[j-1]==-1) p[j]=-1;
				else if(x[j]-x[lst]<=d) p[j]=minn;
				else {
					minn++;
					lst=j;
					if(x[j]-x[j-1]>=d) p[j]=-1;
					else p[j]=minn;
				}  
			} 
			//for (int j=i+1;j<=n;j++){
			//	cout<<p[j]<<" ";
			//} 
			//cout<<'\n';
			for(int j=i+1;j<=n;j++){
				int pre=1;
				//
				a[i][j]=1;
				if(p[j]==-1) continue;
				else if(j-pre<=0) continue;
				else if(p[j-pre]==-1) continue;
				else {
					int re=x[j];
					int k=1;
					if(re-x[j-pre]>d){
						re-=d;
						k++;
					}
				//cout<<x[j]-x[j-pre]<<'\n';
					while(re-x[j-pre]<=d&&j-pre>0) {
						//cout<<p[j-pre]<<" "<<p[j]<<'\n';
						if(p[j]==-1) continue;
						else if(j-pre<=0) continue;
						else if(p[j-pre]==-1) continue;
						if(p[j-pre]+k==p[j]) {
							a[i][j]+=a[i][j-pre];
							//a[i][j+pre]+=a[i][j];
						}
						pre++;
					}
				}
				
			} 
			
		}
		for (int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				//cout<<a[i][j]<<" ";
				if(a[i][j]==3) {
					ans++;
					//cout<<i<<" "<<j<<'\n';
				} 
			} 
			//cout<<'\n';
		}
		
		cout<<ans<<'\n';			
	}
	return 0;
} 
