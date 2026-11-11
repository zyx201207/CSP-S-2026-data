#include<bits/stdc++.h>
using namespace std;
const int M=5e5+10,L=1e3+10,N=510;
int c,n,m,d,q; 
int w[M],k[N],p[N];
int x,y;
int vis[M],vis2[M],ans;
struct line{
	int a[L];
	int t[L];
}l[N];
void dfs(int sta,int time,int pre,int now){
	if(sta==y){
		ans=min(time,ans);
		return;
	}
	for(int i=1;i<=n;i++){//nÌõÏß
		for(int j=1;j<=k[i];j++){
			if(l[i].a[j]==sta){	
				if(vis[l[i].a[j]]>1 && pre!=i){
					for(int h=1;h<=k[i];h++){
						if(h!=j && !vis2[l[i].a[h]]){
							vis2[l[i].a[h]]=1;
							dfs(l[i].a[h],time+l[i].t[j]+l[i].t[h],now,i);
							vis2[l[i].a[h]]=0;
						}
					}			
				}
				else{
					for(int h=1;h<=k[i];h++){
						if(h!=j && !vis2[l[i].a[h]]){
							vis2[l[i].a[h]]=1;
							dfs(l[i].a[h],time,pre,i);
							vis2[l[i].a[h]]=0;
						}
					}					
				}
				break;				
			}
		} 
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i]; 
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>l[i].a[j]>>l[i].t[j];
			vis[l[i].a[j]]++;
			p[l[i].a[j]]=i;
		}
	}
	while(q--){
		cin>>x>>y;
		ans=0x3f3f3f3f;
		vis2[x]=1;
		dfs(x,0,0,p[x]);
		ans+=w[x]+w[y];
		cout<<ans<<endl;
	}
	return 0;
}

