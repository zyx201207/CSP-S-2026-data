#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010];
long long c[500010]={0};
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
		cin>>a[i];
	}    
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		for(int j=1;j<i;j++){
			c[i]+=abs(a[i]-a[j]);
		}
	}
	long long ans=0;
	for(long long i=2;i<=n;i++){
		for(int j=1;j<i;j++){
			if(c[i]-c[j]<=m){
				ans=max(ans,i-j+1);
			}
		}
	}
	cout<<ans<<endl;
	
    return 0;
}
