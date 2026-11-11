#include<bits/stdc++.h>
using namespace std;
int mapp[1005][1005];
int w[500005];
int a[500005],t[500005];
bool flaga=1,flagb=1;
int flagt;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=1005;i++){
		for(int j=1;j<=1005;j++){
			mapp[i][j]=0x3f3f3f3f;
		}
	}
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		if(k>=2)flaga=0;
		for(int j=1;j<=k;j++){
			int a1,t1;
			cin>>a1>>t1;
			if(j==1)flagt=t1;
			else {
				if(t1!=flagt)flagb=0;
			}
			a[j]=a1,t[j]=t1;
		}
		for(int o=1;o<=k;o++){
			for(int p=1;p<=k;p++){
				if(o!=p)mapp[a[o]][a[p]]=min(mapp[a[o]][a[p]],t[o]+t[p]);
			}
		}
	}

	if(flagb==1){
		for(int i=1;i<=q;i++){
			int u,v;
			cin>>u>>v;
			cout<<w[u]+w[v]+2*flagt<<endl;
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			if(i==k)continue;
			for(int j=1;j<=m;j++){
				if(k==j||j==i)continue;
				mapp[i][j]=min(mapp[i][j],mapp[i][k]+mapp[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int u,v;
		cin>>u>>v;
		cout<<w[u]+w[v]+mapp[u][v]<<endl;
	}
	return 0;
}

