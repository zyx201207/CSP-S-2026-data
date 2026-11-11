#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000005],c[1000005],ans;
long long check(long long x,long long y){
	long long sum=(x-y)*a[x]-c[x-1]+c[y-1];
	if(sum<=m) return x-y+1;
	else return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        c[i]=c[i-1]+a[i];
    }
    /*for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if((i-j)*a[i]-c[i-1]+c[j-1]<=m){
				ans=max(ans,1ll*(i-j+1));
				break;
			}
		}
	}*/
	for(int i=1;i<=n;i++){
		long long l=1,r=i,mid;
		while(l!=r){
			mid=(l+r)/2;
			if(check(i,mid)!=0){
				r=mid;
				ans=max(ans,check(i,mid));
			}else{
				l=mid+1;
			}
		}
	}
	cout<<ans;
}
