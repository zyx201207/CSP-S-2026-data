#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int c,n,m,d,q,mp[505][23];bool a[505][23];
int mm[505];
int w[505];
int dfs(int x,int y,int sum){
	if(x==y){
		return sum;
	}
	sum+=w[x];
	for(int k=1;k<=m;k++){
			if(x==k)continue;
			else if(a[x][k]){
				sum+=mp[x][k];
				dfs(k,y,sum);
		}
	}
}
int main(){
//	freopen(".in","r",stdin);
//	freopen(".out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int t;
			int s;
			cin>>s>>t;
			mm[j]=s;
			for(int f=1;f<j;f++){
				mp[mm[f]][j]=t;
				a[mm[f]][j]=1;
			}
		}
	}
	for(int z=1;z<=q;z++){
		int sm=0;
		int mn=N;
		int qd,zd;
		cin>>qd>>zd;
		if(a[qd][zd])mn=mp[qd][zd]+w[qd];
		cout<<min(mn,dfs(qd,zd,sm))<<endl;
	}
	return 0;
}
/*0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2*/
