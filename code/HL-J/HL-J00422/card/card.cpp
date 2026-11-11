#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],ans;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(long long i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    ans=a[n];
    for(long long i=n-1;i>=n-m+1;i--){
    	ans=ans&a[i];
	}
	cout<<ans;
    return 0;
}
