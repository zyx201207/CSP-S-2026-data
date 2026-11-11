#include<bits/stdc++.h>
using namespace std;
struct Sub{
	int s[25],i=0,t[25],w;
	int st[25][25];
}sub[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>sub[i].w;
	for(int i=1;i<=n;i++){
		int x,y;cin>>x;
		for(int j=1;j<=x;j++){
		    cin>>y;
			sub[y].i++;
			cin>>sub[y].t[sub[y].i];
			sub[y].s[sub[y].i]=i;
		}
	}
	int minn[505][505];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
		    minn[i][j]=1e9+5;
	    }
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<sub[i].i;j++)
		    for(int k=j+1;k<=sub[i].i;k++){
		    	sub[i].st[j][k]=sub[i].t[j]+sub[i].t[k];
		    	minn[sub[i].s[j]][sub[i].s[k]]=min(minn[sub[i].s[j]][sub[i].s[k]],sub[i].st[j][k]);
			}
	}
	for(int i=1;i<=m;i++){
		for(int i=1;i<=m;i++){
		    ;
	    }
	}
	return 0;
}
