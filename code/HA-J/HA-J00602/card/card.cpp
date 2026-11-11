#include<iostream>
#include<cstdio>
using namespace std;
int a[500005];
int z[500005];
int ans[300005];
int x=0;
int n,m;
void work(int i){
	z[++x]=a[i];
	for(int j=n;j>=1;--j){
		if(a[j]==a[i]){
			work(j+1);
			break;
		}
	}
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i) cin>>a[i];
	for(int i=1;i<=n;++i){
		x=0;
		work(i);
		for(int j=1;j<=x;++j) ++ans[z[j]];
	}
	for(int i=1;i<=m;++i) cout<<ans[i]<<' ';
	return 0;
}
