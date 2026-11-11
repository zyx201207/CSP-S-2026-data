#include<bits/stdc++.h>
using namespace std;
int s[29999999],sum=0,k[5477][5477],x[100100],y[100100];
struct SB{
	int h,t;
}a[1000][3000];
vector<int> v[100100];
void dfs(int x,int y,int f){
	if(x==y)
	{
		sum+=s[x];
		return;
	}
	int i;
	for(i=0;i<v[x].size();i++)
	{
		int to=v[x][i],shy=0;
		f++;
		if(f==1)
			sum+=s[x]+a[k[x][to]][x].t;
		sum+=a[k[x][to]][to].t;
		dfs(to,y,f);
	}
	
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int i,c,n,m,d,q,p,j;
	cin>>c>>n>>m>>d>>q;
	for(i=1;i<=m;i++){
		cin>>s[i];
	}
	for(i=1;i<=n;i++)
	{
		cin>>p;
		for(j=1;j<=p;j++){
			cin>>a[i][j].h>>a[i][j].t;
			v[a[i][j-1].h].push_back(a[i][j].h);
			k[a[i][j-1].h][a[i][j].h]=i;
		}
	}
	for(i=1;i<=q;i++)
	{
		cin>>x[i]>>y[i];
	}
	for(i=1;i<=q;i++)
	{
		sum=0;
		dfs(x[i],y[i],0);
		cout<<sum<<endl;
	}
	return 0;
}
