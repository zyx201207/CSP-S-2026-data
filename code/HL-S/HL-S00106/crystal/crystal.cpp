#include<bits/stdc++.h>
using namespace std;
long long a[1000000];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }sort(a+1,a+n+1);
    long long ans,sum=0,h;
    for(int i=1;i<=n;i++){
    	ans=0;
    	h=m;
    	for(int j=1;j<=n;j++){
    		if(a[j]==a[i]||abs(a[i]-a[j])<=h)ans++,h-=abs(a[i]-a[j]);
    		if(h==0)break;
		}if(ans>sum)sum=ans;
    }cout<<sum;
    return 0;
}
