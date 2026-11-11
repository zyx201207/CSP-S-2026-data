#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=5e5+5;
ll n,m,a[maxn],b[maxn],mmax;
bool cmp(ll x,ll y){
	return x>y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for (int i=1;i<=n;i++){
		ll sum=m,num=1,x=a[i];
		for (int j=i+1;j<=n;j++){
			if (sum>=x-a[j]) sum-=x-a[j],num++,mmax=max(mmax,num);
			else {
				break;
			}
		} 
	}
	cout<<mmax;
	return 0;
}
