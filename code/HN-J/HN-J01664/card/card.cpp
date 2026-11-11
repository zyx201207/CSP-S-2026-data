#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],now[500010],ans[500010];
//now[i]:最后一个=i的位置 
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		now[a[i]]=i;
	}
	for(int i=1;i<=n;++i){
		int j=i;
		while(j<=n){
			j=now[a[j]];
			++ans[a[j]];
			++j;
		}
	}
	for(int i=1;i<=m;++i) cout<<ans[i]<<" ";
	return 0;
}//Accepted
//不就是拖拉机吗 
