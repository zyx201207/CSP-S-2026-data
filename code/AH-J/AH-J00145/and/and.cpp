#include<bits/stdc++.h>
using namespace std;
long long n,k,a[200005];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	long long t=a[n],ans=0;
	for(int j=1;j<k;j++){
	    t&=a[n-j];
    }
    ans=max(ans,t);
    for(int j=n-1;j>=k;j--){
		if(a[j]<ans) break;
	    t^=a[j+1];
	    t&=a[j-k+1];
	    ans=max(ans,t);
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
