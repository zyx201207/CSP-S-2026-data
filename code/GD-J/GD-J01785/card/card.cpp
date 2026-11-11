#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans[500005];
int num[300005];
queue<int> q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	memset(num,-1,sizeof(num));
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=n;i>=1;i--){
		if(num[a[i]]==-1) num[a[i]]=i;
		int x=i;
		while(x<=n){
			ans[a[x]]++;x=num[a[x]]+1;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
