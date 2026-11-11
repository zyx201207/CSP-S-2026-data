#include<iostream>
using namespace std;
long long c,n,m,d,q,w[500003],k[503],mn;
long long a[503][50003],l[50003][503],t[503][50003];
int lcnt[500003];
bool visA[500003],visB[500003];
void dfs(int p,int tar,long long val){
	if(p==tar){
//		cout<<"!"<<p<<":"<<val<<"\n";
		mn=min(mn,val);
		return;
	}
	if(visA[p])return;
//	cout<<"sta:"<<p<<" $"<<val<<"\n";
	visA[p]=1;
	for(int i=1;i<=lcnt[p];i++){
		int line=l[p][i];
		if(visB[line])continue;
		visB[line]=1;
		long long num;
		for(int z=1;z<=k[line];z++)if(a[line][z]==p)num=val+t[line][z];
//		cout<<"lne:"<<line<<" $"<<num<<"\n";
		for(int j=1;j<=k[line];j++){
			if(visA[a[line][j]])continue;
			dfs(a[line][j],tar,num+t[line][j]);
		}
		visB[line]=0;
	}
	visA[p]=0;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(long long i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			l[a[i][j]][++lcnt[a[i][j]]]=i;
		}
	}
	for(int Case=1;Case<=q;Case++){
		mn=1e18;
		int x,y;
		cin>>x>>y;
		dfs(x,y,0);
		cout<<mn+w[x]+w[y]<<endl;
	}
	return 0;
} 
