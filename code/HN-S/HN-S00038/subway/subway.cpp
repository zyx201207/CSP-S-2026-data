#include<bits/stdc++.h>
using namespace std;
struct node{
	int id,t;
}a[205][25];
int c,n,m,d,q;
int s[405],f[405][405],bo[405][405];
vector<int>v[405];
int dfs(int la,int now,int r,int sum){
	if(now==r){
		return sum;
	}
	int minn=0x3f3f3f3f;
	for(int i=0;i<v[now].size();i++){
		if(bo[la][now]){ 
			bo[now][la]=0;
			bo[la][now]=0;
			minn=min(minn,dfs(now,v[now][i],r,sum+f[now][v[now][i]]));
			bo[now][la]=1;
			bo[la][now]=1;
		}
	}
	if(minn==0x3f3f3f3f)return sum;
	return minn;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		for(int j=1;j<=x;j++){
			cin>>a[j][i].id>>a[j][i].t;
		}
		for(int j=1;j<=x;j++){
			for(int k=j+1;k<=x;k++){
				int p=a[j][i].id,q=a[k][i].id;
				bo[p][q]=1,bo[q][p]=1;
				v[p].push_back(q);
				v[q].push_back(p);
				int tim=a[j][i].t+a[k][i].t;
				f[j][k]=min(f[j][k],tim);
				f[k][j]=min(f[k][j],tim);
			}
		}
	}
	for(int i=1;i<=q;i++){
		long long ans=0;
		int x,y;
		cin>>x>>y;
		ans=s[x]+s[y];
		bo[0][x]=1;
		ans+=dfs(0,x,y,0);
		cout<<ans;
	}
	return 0;
}

