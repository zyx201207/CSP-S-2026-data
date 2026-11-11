#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans=1,sum;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long cnt=1,ii=1;
	for(int i=2;i<=n;i++){
		sum=(a[i]-a[i-1])*(i-ii)+sum;
		if(sum>m){
			ans=max(ans,cnt);
			while(sum>m){
				sum=sum-a[i]+a[ii];
				ii++;
				cnt--;
			}
		}
		cnt++;
	}
	ans=max(ans,cnt);
	cout<<ans;
	return 0;
}
