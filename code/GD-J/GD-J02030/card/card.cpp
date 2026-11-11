#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
int n,m,a[N],lst[N],pos,ans[N]; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=n;i>=1;i--){
		if(!lst[a[i]]) lst[a[i]]=i;
	}
	for(int i=1;i<=n;i++){//O(N^2) 
		pos=i;
		while(pos<=n){
			ans[a[pos]]++, pos=lst[a[pos]]+1;//直接跑到最后面 
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
/*
暴力大法好 
*/
