#include<bits/stdc++.h>
using namespace std;

int c,t,n,d,ans,x[2000005],f[2000005],g[2000005];

int main(){
	
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	cin>>c>>t;
	while(t--){
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		for(int i=1;i<=n;i++){
			fill(f+1,f+1+n,2147483647);
			fill(g+1,g+1+n,0);
			f[i]=0;
			queue<int> q;
			q.push(i);
			while(!q.empty()){
				int now=q.front();
				q.pop();
				for(int j=1;j<=n;j++){
					if(abs(x[j]-x[now])<=d){
						if(f[j]==f[now]+1){
							g[j]++;
							if(g[j]>=2){
								ans--;
							}
							if(g[j]==2){
								ans--;
							}
							ans++;
						}
						else if(f[j]==2147483647){
							f[j]=f[now]+1;
							q.push(j);
						}
					}
				}
			}
		}
		cout<<ans/2<<endl;
	}
	
	return 0;
}
