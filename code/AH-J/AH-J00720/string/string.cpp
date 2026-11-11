#include <bits/stdc++.h>
using namespace std;
long long n,a[100010],sum[100010],m,ans;
char c[100100];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum[i]=sum[i-1]+a[i];
	}
	ans=sum[n]/2;
	for(int i=1;i<=n/2;i++){
		for(int j=0;j<=n/2-i;j++){
			if(c[i]==c[n-i+1-j]){
				ans-=min(a[i],(sum[n-i+1-j]-sum[n-i-j]));
				if(a[i]<sum[n]-sum[n-i-j]){
				break;	
				}
			}
			else{
			break;	
			}
		}
	}
	cout<<ans;
	return 0;
}
/*if(c[i]==c[n-i+1]){
			ans-=min(a[i],(sum[n-i+1]-sum[n-i]));
			a[i]-=(sum[n-i+1]-sum[n-i]);
		}*/
