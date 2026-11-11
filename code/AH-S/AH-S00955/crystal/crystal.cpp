#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],qz[500005],ans=0;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
		qz[i]=qz[i-1]+a[i];
    for(int i=2;i<=n;i++){
		long long l=1,r=i,mid;
		while(l!=r){
		    mid=(l+r+1)/2;
		    if(qz[i]-qz[mid-1]+m>=a[i]*(i-mid+1)){
			    if(i-mid>ans) ans=i-mid;
			    r=mid-1;
			}else l=mid;
		}
		if(qz[i]-qz[r-1]+m>=a[i]*(i-r+1))
			    ans=i-r;
	}
	cout<<ans+1;
    fclose(stdin); fclose(stdout);
    return 0;
}
