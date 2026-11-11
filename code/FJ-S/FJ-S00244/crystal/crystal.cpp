#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll m,a[500005];
ll n,ans=-0x3f3f3f3f;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	ll num,mm;
for(ll i=a[0];i<=a[n-1];i++){
	num=0,mm=m;
for(ll j=0;j<n&&a[j]<=i;j++)
	{
	if(mm>=i-a[j])mm-=i-a[j],num++;
	}
	if(num>ans)ans=num;
}
	cout<<ans;
	return 0;
} 
