#include<iostream>
#include<algorithm> 
#include<vector>
#include<cstring>
using namespace std;
#define int long long 
const int MAXN=2e6+100;
int C,T; 
int n,d,p[MAXN];
int dfs(int u,int v,int m){
	if(m==0){
		for(int k=u;p[k]-p[u]<=d&&k<=v;k++)
			if(k==v)
				return 1;
		return 0;
	}
	int res=0;
	for(int k=u+1;p[k]-p[u]<=d&&k<=v;k++)
		res+=dfs(k,v,m-1);
	return res;
}
bool ck(int u,int v){
	int cnt=0,m=0;
	for(int i=u;i<=v;i++){
		int k=i;
		for(;p[k]-p[i]<=d&&k<=v;k++);
		k--;
		m++;
		if(k>=v)
			break;
		i=k;
	}
	if(dfs(u,v,m)==2)
		return true;
	return false;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>C>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)
			cin>>p[i];
		if(C==11||C==12){
			if((p[2]-p[1])*2>d)
				cout<<0<<'\n';
			else
				cout<<n-3<<'\n';
			continue;
		}
		for(int i=2;i<=n;i++)
			p[i]-=p[1];
		p[1]=0;
		int cnt=0;
		for(int i=1;i<=n;i++)
			for(int j=i+3;j<=n;j++)
				if(ck(i,j))
					cnt++;
		cout<<cnt<<'\n';
	}
	return 0;
} 
