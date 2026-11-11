#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=5e5+10;
ll n,m,sum,ans,d,a[N],pre1[N],pre2[N];
bool cs1=true,cs2=true;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i],pre1[i]=pre1[i-1]+a[i];
		if(a[i]!=i) cs1=false;
	}
	for(ll i=2;i<n;i++){
		d=a[i]-a[i-1];
		if(d!=a[i+1]-a[i]) cs2=false;
	}
	for(ll i=1;i<=n;i++){
		pre2[i]=d*i;
		pre2[i]+=pre2[i-1];
	}
	if(cs1){
		for(ll i=1;i<=n;i++){
			if(pre1[i-1]>m) break;
			ans=i;
		}
	}else if(cs2){
		for(ll i=1;i<=n;i++){
			if(pre2[i-1]>m) break;
			ans=i;
		}
	}else{
		sort(a+1,a+n+1);
		for(ll i=1;i<=n;i++){
			ll j=i-1,sum=0;
			for(;j>=1;j--){
				sum+=a[i]-a[j];
				if(sum>m) break;
			}
			ans=max(ans,i-j);
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
