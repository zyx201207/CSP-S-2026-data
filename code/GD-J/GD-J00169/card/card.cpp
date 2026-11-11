#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],x[N],ans[N],v[N],p[N];
struct G{
	int x,y;
}g[N],w[N];
bool cmp(G a,G b){
	return a.y<b.y;
}
signed main(){
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=0;j<N;j++)
			x[j]=v[j]=p[j]=0;
		for(int j=i;j<=n;j++){
			if(!x[a[j]])
				x[a[j]]=j;
			v[a[j]]=1;
		}
		int nn=0,n1=0;
		for(int j=n;j>=i;j--)
			if(x[a[j]]<j){
				for(int k=x[a[j]];k<=j-1;k++)
					p[a[k]]=1;
			}
		for(int j=1;j<=m;j++){
			if(!p[j]&&v[j])
				ans[j]++;
			cout<<p[j]<<" ";
		}
		cout<<"\n";
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	return 0;
}
