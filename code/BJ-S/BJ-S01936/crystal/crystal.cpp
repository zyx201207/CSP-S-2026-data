#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[500005],n,m,k,c[500005],sum;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) c[i]=(i-1)*(a[i]-a[i-1]);
    for(int i=1;i<=n;i++){
		sum+=c[i];
		if(sum>m){
		    cout<<i-1;
		    return 0;	
	    }
    }
    cout<<n;
    return 0;
}
