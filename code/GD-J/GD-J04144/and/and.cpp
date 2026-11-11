#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[200005],pre[200005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    cin>>a[1];
    for(int i=2;i<=n;i++){
	    cin>>a[i];
		ans=max(ans,a[i]&a[i-1]);
	}
	cout<<ans;
	return 0;
} 
