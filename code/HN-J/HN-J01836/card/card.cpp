#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500101],ans[500101];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(ans[a[i]]<i)ans[a[i]]=i;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}

