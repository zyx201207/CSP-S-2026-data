//在原有基础上尝试以i为起点二分优化 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=5e5+7;
int n,a[maxn];
ll m;
ll s[maxn],d[maxn],ans;
struct node{
	ll cnt,num;
}g[maxn];
bool check(int i,int j){
	ll cost=(j-i+1)*a[j]-s[j]+s[i-1];
	if(cost>m) return false;
	return true;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
		d[i]=a[i]-a[i-1];
	}
	for(ll i=1;i<=n;i++){
		int l=i,r=n,mid=0;
		while(l<r){
			mid=(l+r)/2;
			if(check(i,mid)) l=mid+1;
			else r=mid;
		}
		ans=max(ans,mid-i+1);
	}
	cout<<ans;
//	for(int i=1;i<=n;i++) cout<<a[i]<<" "<<s[i]<<" "<<d[i]<<" ";
	return 0;
} 
