#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll m,n;
ll a[500005];
ll cnt=1;
ll ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&m,&n);
	for(int i=1;i<=m;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+m+1);
	bool temp=false;
	bool found=false;
	for(int i=1;i<=m-1;i++){
		if(temp==true)	break;
		ll sum=a[i+1]-a[i];
		sum*=i;
		if(sum>n){
			temp=true;
			break;
		}
		else{
			n-=sum;
			cnt++;
		}
	}
	for(int i=m;i>=2;i--){
		if(found==true)	break;
		ll sum=a[i]-a[i-1];
		sum*=(m-i+1);
		if(sum>n){
			found=true;
			break;
		}
		else{
			n-=sum;
			ans++;
		}
	}
	cout<<max(cnt,ans);
	return 0;
} 
