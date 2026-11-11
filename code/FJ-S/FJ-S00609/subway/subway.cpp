#include<bits/stdc++.h>
using namespace std;
vector<int> lg[500010];
int c,n,m,d,q;
long long w[500010];
unordered_map<int,long long> t[510];
long long s[510][510];
long long _in(){
	long long x=0;
	long long f=1;
	char c=getchar();
	while((c<'0'||c>'9')&&(c!='-')){
		c=getchar();
	}
	if(c=='-'){
		f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return f*x;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	freopen("C:\\Users\\Administrator\\Desktop\\subway\\subway7.in","r",stdin);
//	freopen("C:\\Users\\Administrator\\Desktop\\a.out","w",stdout);
	c=_in();
	n=_in();
	m=_in();
	d=_in();
	q=_in();
	for(int i=1;i<=m;i++){
		w[i]=_in();
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			s[i][j]=1e18;
			if(i==j){
				s[i][j]=0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		int k=_in();
		for(int j=1;j<=k;j++){
			int a=_in();
			long long ti=_in();
			t[i][a]=ti;
			if(lg[a].size()>0){
				for(int l=0;l<lg[a].size();l++){
					s[lg[a][l]][i]=min(s[lg[a][l]][i],t[lg[a][l]][a]+ti);
					s[i][lg[a][l]]=min(s[i][lg[a][l]],ti+t[lg[a][l]][a]);
				}
			}
			lg[a].push_back(i);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=n;k++){
				s[j][k]=min(s[j][k],s[j][i]+s[i][k]);
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x=_in(),y=_in();
		long long ans=1e18;
		for(int j=0;j<lg[x].size();j++){
			for(int k=0;k<lg[y].size();k++){
				int u=lg[x][j],v=lg[y][k];
				ans=min(ans,w[x]+t[u][x]+s[u][v]+t[v][y]+w[y]);
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
