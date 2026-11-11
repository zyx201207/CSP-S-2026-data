#include <bits/stdc++.h>
using namespace std;
long long n,i,j,k,x,y,m,a[500005],cnt,ans,l,sum;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ans=1;
	cnt=1;
	l=1;
	sum=0;
	for(i=2;i<=n;i++){
		k=a[i]-a[i-1];
		sum+=k*cnt;
		while(sum>m){
			sum-=a[i]-a[l];
			l++;
			cnt--;
		}
		cnt++;
		ans=max(ans,cnt);
		
	}
	cout<<ans;
	return 0;
} 
