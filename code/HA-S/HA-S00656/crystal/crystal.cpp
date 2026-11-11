#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll m;
int n,a[500005],t[500005],maxn=-0x7fffffff;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		t[a[i]]++;
		maxn=max(a[i],maxn);
	}
	if(m==0){	
		sort(t,t+1+maxn);
		cout<<t[maxn];
		return 0;
	}
	else if(m>=1000000000000000000){
		cout<<n;
		return 0;
	}
	sort(a+1,a+1+n);
	ll k=(n+1)/2,sum=0,sum1=0,ans=0,ans1=0;
	for(int i=k-1;i>=1;i--){
		if(a[i]==a[k]) continue;
		sum=sum+abs(a[i+1]-a[i]);
		ans++;
		if(sum==m){
			break;
		}
	}
	for(int i=k+1;i<=n;i++){
		if(a[i]==a[k]) continue;
		sum1=sum1+abs(a[i]-a[i-1]);
		ans1++;
		if(sum1==m){
			break;
		}
	}
	cout<<max(ans1,ans)+t[a[k]];
	return 0;
} 
