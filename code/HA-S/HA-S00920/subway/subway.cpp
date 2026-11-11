#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[500004],k[504],e[500004],x,y,g,h,r,s;
vector<long long>a[504],t[504],b[504];
vector<bool>p[504];queue<int>l,o;
void f(int x){for(int i=1;i<=n;i++)for(int j=0;j<k[i];j++)b[i][j]=2004006008;
	for(int i=1;i<=m;i++)e[i]=2004006008;for(int i=1;i<=n;i++)for(int j=0;j<k[i];j++)p[i][j]=0;
	for(int i=1;i<=n;i++)for(int j=1;j<=k[i];j++)if(a[i][j]==x)
		l.push(i),o.push(j),e[x]=min(t[i][j]*2,e[x]),b[i][j]=min(t[i][j]*2,b[i][j]),p[i][j]=1;
	while(!l.empty()){r=l.front();s=o.front();l.pop();o.pop();for(int i=0;i<k[r];i++){
	l.push(r),o.push(i),e[a[r][i]]=min(e[a[r][s]]-t[r][s]+t[r][i],e[a[r][i]]),
	b[r][i]=min(b[r][s]-t[r][s]+t[r][i],b[r][i]),p[r][i]=1;}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){cin>>k[i];for(int j=0;j<k[i];j++){
		cin>>g>>h;a[i].push_back(g);t[i].push_back(h);b[i].push_back(0);p[i].push_back(0);}}
	while(q--){
		cin>>x>>y;
		f(x);
		cout<<0;
	}
	return 0;
}
