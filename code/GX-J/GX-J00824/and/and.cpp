#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,ans=0;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n-m;i++)
		for(int j=i+1;j<i+1+m;j++)
		    ans=max(ans,a[i]&a[j]);
	ans=max(ans,a[n-2]&a[n-1]);
    cout<<ans;
    return 0;
}
