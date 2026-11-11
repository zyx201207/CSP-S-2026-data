#include<bits/stdc++.h>
using namespace std;
long long m,n,a[500010],t,ans,sum,mx,need;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(long long l=1,r=1;r<=n;r++){
		sum+=a[r];need=a[r]*(r-l+1);
		while(sum+m<need){
			need-=a[r];
			sum-=a[l];
			l++;
		}
		mx=max(mx,r-l+1);
	}
	cout<<mx;
	
	return 0;
} 
