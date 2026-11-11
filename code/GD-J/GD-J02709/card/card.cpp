#include<iostream>
#define N 500005
#define M 300005
using namespace std;
int n,m,a[N],ans[M],t[M],b[N],cnt=0;
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) t[i]=0;
	for(int i=n;i>=1;i--){
		if(!t[a[i]]) t[a[i]]=cnt+1;
		else cnt=t[a[i]]-1;
		b[++cnt]=a[i];
		for(int j=1;j<=cnt;j++)	ans[b[j]]++;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
