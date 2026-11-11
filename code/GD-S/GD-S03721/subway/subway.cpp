#include<bits/stdc++.h>
using namespace std;
/*long long c,n,m,d,p;
long long w[1005],k,web[1005][1005][2];
int main(){
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		
	}
	return 0;
}*/
long long c,n,m,d,q,s1,s2,x,y;
long long k[405],a[405][1005],f[405];
struct st{
	long long w,d=0;
	long long line[20][2];
}v[1005];

long long dfs(long long now,long long end,long long li){
	f[now]=1;
	if(now==end){
		return v[now].w;
	}
	long long ret=99999999;
	for(int i=1;i<=v[now].d;i++){
		long long nli=v[now].line[i][0];
		for(int j=1;j<=m;j++){
			cout<<"debug1"<<endl; 
			if(a[nli][j]==1 && f[j]==0){
				ret=min(ret,dfs(j,end,nli)+v[now].line[nli][1]+v[j].line[nli][1]);
				//cout<<dfs(j,end,nli)+v[now].line[nli][1]+v[j].line[nli][1];
			}
		}
	}
	f[now]=0;
	return ret;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	//return 0;
	for(int i=1;i<=m;i++){
		cin>>v[i].w;
		f[i]=0;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			a[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>s1>>s2;
			a[i][s1]=1;
			v[s1].d++;
			v[s1].line[d][0]=i;
			v[s1].line[d][1]=s2;
		}
	}
	
	//return 0;
	s1=9999999;
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		for(int j=1;j<=m;j++){
			if(a[i][x]&&a[i][y]){
				s1=min(s1,v[x].w+v[y].w+v[x].line[i][1]+v[y].line[i][1]);
			}
		}
	}
	cout<<s1;
	return 0;
}

