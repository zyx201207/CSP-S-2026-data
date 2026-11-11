#include<bits/stdc++.h>
using namespace std;
long long c,t;
struct node{
	long long k;
	long long step;
};
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int _=1;_<=t;_++){
		long long n,d,ans=0;
		cin>>n>>d;
		long long x[2000005];
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				long long ste=0;
				long long sum=0;
				long long vis[2000005];
				memset(vis,0,sizeof(vis));
				queue<node>q;
				node s;
				s.k=i;
				s.step=0;
				q.push(s);
				while(!q.empty()){
					node xx=q.front();
					q.pop();
					vis[xx.k]=1;
					if(xx.k==j){
						if(ste==0) ste=xx.step,sum++;
						else if(ste<xx.step) break;
						else if(ste==xx.step&&sum==2){
							sum=3;
							break;
						}
						else if(ste==xx.step) sum++;
					}
					else{
						for(long long mm=xx.k+1;x[mm]-x[xx.k]<=d;mm++){
							if(!vis[mm]) {
								node ttt;
								ttt.k=mm;
								ttt.step=xx.step+1;
								q.push(ttt);
							}
						}
					}
				}
				if(sum==2) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
