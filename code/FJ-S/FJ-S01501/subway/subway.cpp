#include<bits/stdc++.h>
using namespace std;
int k[510],w[500010],dis[510][500010],g[1010][1010],cnt;
struct node{
	int a,t;
}s[510][500010];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>s[i][j].a>>s[i][j].t;
			dis[i][s[i][j].a]=s[i][j].t;
		}
	} 
	for(int i=1;i<=q;i++){
		int x,y;
		long long t=0,ans=0,id1,id2;
		cin>>x>>y;
		ans=ans+w[x]+w[y];
		for(int j=1;j<=n;j++){
			if(dis[j][x]!=0){
				ans+=s[j][x];
				id1=j;
			}
			if(dis[j][y]!=0){
				ans+=s[j][y];
				id2=j;
			}
		}
		if(id1!=id2){
			int f=1;
			for(int j=1;j<=k[id1];j++){
				for(int kk=1;kk<=k[id2];kk++){
					if(s[id1][j].a==s[id2][kk].a){
						ans=ans+s[id1][j].t+s[id2][kk].t;
						f=0;
						break;
					}
				}
				if(f==0) break;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

