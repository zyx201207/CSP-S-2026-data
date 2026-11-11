#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
typedef long long ll;
ll m,a[N],c[N],s[N],s2[N],s3[N],s4[N];
int n;
bool check(int d){
	for(int i=d;i<=n;i++){
		ll sum=s2[i-d+1]-s3[i]+(s4[n-1]-s4[i-1])*(i-d);
		if(sum<=m)return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)c[i]=a[i+1]-a[i];
	for(int i=1;i<=n;i++)s4[i]=s4[i-1]+c[i];
	for(int i=n;i>=1;i--){
		s[i]=s[i+1]+c[i];
		s2[i]=s2[i+1]+s[i];
		s3[i]=c[i]*i+s3[i+1];
	}
	int l=1,r=n;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(check(mid)){
			l=mid;
		}else{
			r=mid-1;
		}
	}
	cout<<l;
	return 0;
}
