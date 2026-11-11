#include<bits/stdc++.h>

using namespace std;

#define int long long
//y0,y1 nope
//Oct31==Dec25?
//2:57 T2
//freopen("
//play.petalwar.top awa
//could i get 300 points?
/*
998244353
Im -lyy-
luogu:lyy0918lyy 
OvO
*/

int w[500005];

int w2[500005][25];
int t2[500005][25];

int mi[505][505];

int read(){
	char gc=getchar();
	int ans=0;
	bool g=0;
	if(gc=='-'){
		g=true;
		gc=getchar();
	}
	while('0'<=gc&&gc<='9'){
		ans*=10;
		ans+=(gc^48);
		gc=getchar();
	}
	return (g?-ans:ans);
}

signed main(){

	memset(mi,0x3f,sizeof(mi));

	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);

	int c,n,m,d,q;
	c=read();n=read();m=read();d=read();q=read();
	
	for(int i=1;i<=m;i++){
		w[i]=read();
	}
	//cout<<clock()<<endl;
	for(int i=1;i<=n;i++){
		int vc=0,v2;
		vc=read();
		for(int j=1;j<=vc;j++){
			v2=read();
			w2[v2][++w2[v2][0]]=i;
			t2[v2][w2[v2][0]]=read();
		}
	}
	//cout<<clock()<<endl;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=w2[i][0];j++){
			for(int k=1;k<=j;k++){
				if(w2[i][j]==w2[i][k])mi[w2[i][j]][w2[i][k]]=0;
				else mi[w2[i][j]][w2[i][k]]=
					mi[w2[i][k]][w2[i][j]]=
					min(t2[i][k]+t2[i][j],mi[w2[i][k]][w2[i][j]]);
			}
		}
	}
	//cout<<clock()<<endl;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j)continue;
			if(mi[i][j]==mi[0][0])continue;
			for(int k=1;k<j;k++){
				if(mi[i][k]==mi[0][0])continue;
				mi[j][k]=mi[k][j]=min(mi[k][j],mi[i][j]+mi[i][k]);
			}
		}
	}
	//cout<<clock()<<endl;
	for(int i=1;i<=n;i++)mi[i][i]=0;
	//cout<<clock()<<endl;
	for(int i=1;i<=q;i++){
		int x,y,ans=LLONG_MAX;
		x=read();y=read();
		for(int j=1;j<=w2[x][0];j++){
			for(int k=1;k<=w2[y][0];k++){
				ans=min(ans,mi[w2[x][j]][w2[y][k]]+t2[x][j]+t2[y][k]);
			}
		}
		printf("%lld\n",ans+w[x]+w[y]);
	}

	return 0;
}

