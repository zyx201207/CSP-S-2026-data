#include <bits/stdc++.h>
using namespace std;
long long mn=LONG_MAX;
int c,n,m,d,q;
long long ans;
int w[50005];
bool qg[50005];
struct sub{
	int k=0;
	int e[20005];
	long long t[20005];
};
sub a[505];
int pe[50005];
int qe[50005];
long long r[505][505];
void dfs(int d,long long tm,int end){
	if(d==end){
		mn=min(tm,mn);
	}
	for(int i=1;i<=n;i++){
		if(r[i][d]){
			for(int j=1;j<=m;j++){
				if(j!=d&&r[i][j]&&qg[j]==0){
					qg[j]=1;
					dfs(j,tm+r[i][d]+r[i][j],end);
					qg[j]=0;
				}
			}
		}
	}
	return ;
}
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>a[i].k;
		for(int j=1;j<=a[i].k;j++){
			cin>>a[i].e[i]>>a[i].t[i];
			r[i][a[i].e[i]]=a[i].t[i];
		}
	}
	for(int i=1;i<=q;i++){
		mn=LONG_MAX;
		cin>>pe[i]>>qe[i];
		ans=w[pe[i]]+w[qe[i]];
		dfs(pe[i],0,qe[i]);
		cout<<mn+ans<<endl;
	}
	return 0;
}
