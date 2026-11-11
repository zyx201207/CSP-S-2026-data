/*
-------------------------------------
lougu ccp0721:time 17.25 : ºÃÄÑ°¡!!!(Q. _.Q) 
-------------------------------------
*/
#include<bits/stdc++.h>//T1
#define int long long
using namespace std;
int n,m,x,cnt,a[500001],ans=-1e9,sum,f;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	if(a[2]-a[1]==a[3]-a[2]&&a[n]-a[n-1]==a[2]-a[1]){
		for(int i=n;i>=1;i--){
			if(cnt+n-i>m)break;
			else cnt+=n-i;
		}
		cout<<cnt;
	}
	for(int i=n;i>=1;i){
		cnt=0;
		sum=0;
		x=m;
		for(int j=i-1;j>=1;j--){
			if(a[i]==a[j]){
				cnt++;
				sum++;
			}
			else break;
		}
		for(int j=i-cnt;j>=1;j--){
			if(x>=a[i]-a[j]){
				x-=a[i]-a[j];
				sum++;
			}
			else break;
		}
		ans=max(ans,sum);
		if(ans==n)break;
		if(cnt==0)cnt=1;
		i-=cnt;
	}
	cout<<ans;
	return 0;
}
