#include<bits/stdc++.h>
using namespace std;
unsigned long long n,a[200010],sq,sh,ans;///////////////////
char c[200010];///////////////////////
int main(){
	freopen("string4.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(unsigned long long i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(unsigned long long i=1;i<=(n+1)/2;i++){
		if(sh!=0){
			if(sh>=a[i]){
				sh-=a[i];
				ans+=a[i];
				sq+=a[n-i+1];
				continue;
			}
			if(sh<a[i]){
				a[i]-=sh;
				ans+=sh;
				sh=0;
			}
		}
		if(sq!=0){
			if(sq>=a[n-i+1]){
				sq-=a[n-i+1];
				ans+=a[n-i+1];
				sq+=a[i];
				continue;
			}
			if(sq<a[n-i+1]){
				a[n-i+1]-=sq;
				ans+=sq;
				sq=0;
			}
		}
		if(i==n-i+1)break;
		if(a[i]<=a[n+1-i]&&c[i]!=c[n+i-1]){
			sh=a[n+1-i]-a[i];
			ans+=a[i];
		}
		else if(a[i]>a[n+1-i]&&c[i]!=c[n+i-1]){
			sq=a[i]-a[n+1-i];
			ans+=a[n+1-i];
		}
	}
	cout<<ans;
	return 0;
}