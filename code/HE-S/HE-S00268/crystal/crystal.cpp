#include <bits/stdc++.h>
using namespace std;
typedef  long long ll;
const int N=5e5+10;
ll n,m,a[N],num[N],ans;
bool f1=1,f2=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>100){
			f1=0;
		}
		if(i>=3){
			if(a[i]-a[i-1]!=a[i-1]-a[i-2]){
				f2=0;
			}
		}
	}
	if(n<=5000 || f1){
		sort(a+1,a+n+1);
		num[1]=a[1];
		for(int i=2;i<=n;i++){
			num[i]+=num[i-1]+a[i];
		}
		for(int i=1;i<=n;i++){
			if(num[i]+m>=a[i]*i){
				ans=i;
			}
		}
		cout<<ans;
		return 0;
	}
	if(f2){
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			if(i*a[i]/2<=a[1]*i/2+m){
				ans=i;
			}
		}
		cout<<ans;
	}
	return 0;
} 
