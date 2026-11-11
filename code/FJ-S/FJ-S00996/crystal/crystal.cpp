#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll a[500005];
ll b,ans1,ans2;
int main(){
	freopen("crystal1.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;i++){
		b+=a[n]-a[i];     
	}
	b-=m;
	ll b1 = b;
	ll b2 = b;
	int k = 1;
	for(int i = n;i >= 1;i--){
		if((a[i]-a[i-1])*(i-1)<b1){
			b1-=(a[i]-a[i-1])*(i-1);
		}else if((a[i]-a[i-1])*(i-1)==b1){
			ans1 = i-1;
			break;
		}else{
			ans1 = i;
			break;
		}
	}
	for(int i = n;i >= k;){
		if((a[i]-a[i-1])*(i-k)<=b){
			if(a[i]-a[k]>=(a[i]-a[i-1])*(i-k)){
				b-=(a[i]-a[k]);
				k++;
			}else{
				b-=(a[i]-a[i-1])*(i-k);
				i--;
			}
		}else{
			ans2 = i-k+1;
			break;
		}
	}
	cout<<max(ans1,ans2);
	return 0;
} 
