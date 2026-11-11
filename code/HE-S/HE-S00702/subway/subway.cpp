#include<bits/stdc++.h>
using namespace std;
const int N=510,M=5e5+10;
int c,n,m,d,q;
long long w[M],k[N];
vector<pair<int,long long>> b[M];
long long f[N][N];
inline long long read(){
	long long cnt=0,pd=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			pd=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		cnt=(cnt<<1)+(cnt<<3)+(ch^48);
		ch=getchar();
	}
	return cnt*pd;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=read();
	n=read();
	m=read();
	d=read();
	q=read();
	for(int i=1;i<=m;i++){
		w[i]=read();
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			long long ra,rt;
			ra=read();
			rt=read();
			b[ra].push_back(make_pair(i,rt));
		}
	}
	memset(f,0x3f,sizeof f);
    for(int i=1;i<=m;i++){
    	for(int j=0;j<b[i].size();j++){
    		for(int k=j+1;k<b[i].size();k++){
    			f[b[i][j].first][b[i][k].first]=f[b[i][k].first][b[i][j].first]=min(f[b[i][j].first][b[i][k].first],b[i][j].second+b[i][k].second);
			}
		}
	}
	for(int i=1;i<=n;i++){
		f[i][i]=0; 
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				f[i][j]=f[j][i]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	for(int qid=1;qid<=q;qid++){
		int qx,qy;
		qx=read();
		qy=read();
		long long ans=1e18;
		for(int i=0;i<b[qx].size();i++){
			for(int j=0;j<b[qy].size();j++){
				ans=min(ans,w[qx]+w[qy]+b[qx][i].second+b[qy][j].second+f[b[qx][i].first][b[qy][j].first]);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
