#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500050];
long long check(long long now){
	long long cnt=0;
	long long sum=m;
	for(int i=n;i>=1;i--){
		if(a[i]>now){
			continue;
		}
		if(sum-abs(now-a[i])>=0){
			sum-=now;
			sum+=a[i];
			cnt++;
		}else{
			return cnt;
		}
	} 
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long ans=0;
	for(int i=a[1];i<=a[n];i++){
		if(check(i)>ans){
			ans=check(i);
		}
	}
	cout<<ans;
	return 0;
}
