#include<bits/stdc++.h>
using namespace std;
int m,n,t,a[200005],ans[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		if(ans[a[i]]<i) ans[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		cout<<ans[a[i]]<<" ";
	}
	return 0;
}
