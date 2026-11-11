#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define LL __int128
#define inf 0x3f
#define Inf 0x3f3f3f3f3f3f3f3f
const int N=5e5+5;
ll n,m;
ll a[N],s[N];
ll ans;
ll mx,k;
ll f1=0,f2=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;	
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		if(a[i]!=i) f1=1;
		k=max(k,abs(a[i]));
	}
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=a[i-1]-a[i-2]) f2=1;
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	if(n<=5000){
 		for(int i=1;i<=n;i++){
 			ll p=lower_bound(a+1,a+1+n,a[i]+1)-a-1;
 			ll ans=0,sum=0;
 			for(int j=p;j>=1;j--){
 				sum=sum+a[i]-a[j];
 				if(sum<=m) ans++;
		 	}
			 mx=max(mx,ans);
	 	}
		 cout<<mx;
	}
	else if(k<=100){
		for(int i=-k;i<=k;i++){
 			ll p=lower_bound(a+1,a+1+n,i+1)-a-1;
 			ll ans=0,sum=0;
 			for(int j=p;j>=1;j--){
 				sum=sum+i-a[j];
 				if(sum<=m) ans++;
		 	}
			 mx=max(mx,ans);
	 	}
		cout<<mx;
	}
	else if(!f1||!f2){
		ll sum=0;
		for(int i=1;i<=n;i++){
			if((i-1)*a[i]-sum<=m) mx=i;
			else break;
			sum+=a[i];
		}
		cout<<mx;
	}
	else{
		for(int i=1;i<=n;i++){
 			ll sum=a[i]*i-s[i];
 			if(sum<=m) mx=i;
 			else{
 				sum-=m;
 				ll l=1,r=i-1,mid=0,q=0;
 				while(l<=r){
 					mid=(l+r)/2;
 					if(a[i]*mid-s[mid]>=sum){
 						q=mid;
 						r=mid-1;
					 }
					 else{
					 	l=mid+1;
					 }
				 }
				 mx=max(mx,i-q);
			 }
	 	}
		 cout<<mx;
	}
	return 0;
}
