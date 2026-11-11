#include<bits/stdc++.h> 
using namespace std;
int n,m,a[500005],ans[300005],desk[500005],x,d[300005],p[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	for(int i=0;i<n;++i){
		x=0;
		memset(d,0,sizeof(d));
		memset(p,0,sizeof(p));
		for(int j=1+i;j<=n;++j){
			if(d[a[j]])x=p[a[j]];
			else{
				desk[++x]=a[j];
				d[a[j]]=true;
				p[a[j]]=x;
			}
		}
		for(int j=1;j<=x;++j)ans[desk[j]]++;
	}
	for(int j=1;j<=m;++j)cout<<ans[j]<<" ";
	return 0;
}
