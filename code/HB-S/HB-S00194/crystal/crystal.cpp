#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[500005],m,ans,sum[500005],diff[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		diff[i]=a[i]-a[i-1];
	}
	int flag=0;
	for(int i=1;i<n;i++){
		if(diff[i]!=diff[i+1]){
			flag=1;
		}
	}
	if(flag==0){
		long double k=sqrt(8*m/diff[1]+1)-1;
		int k1=k/2;
		cout<<k1+1;
		return 0;
	}
	sort(a+1,a+n+1);
	ll c[500005];
	for(int i=1;i<=n;i++){
		ll p=1,k=m;
		memset(c,0,sizeof(c));
		for(int j=1;j<i;j++){
			c[j]=a[i]-a[j];
		}
		for(int j=i-1;j>=1;j--){
			if(k-c[j]<0){
				break;
			}
			else{
				k-=c[j];
				p++;
			}
		}
		ans=max(p,ans);
	}
	cout<<ans;
	return 0;
}
