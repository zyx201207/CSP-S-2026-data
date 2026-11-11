#include <bits/stdc++.h>
using namespace std;
long long n,a[500005],m,ans=1;
void num(long long s){
	long long x=a[s];
	long long cnt=m;
	long long sum=1;
	for(int i=s-1;i>=1;i--){
		if(cnt>=a[s]-a[i]){
			sum++;
			cnt-=(a[s]-a[i]);
		}else{
			break;
		}
	}
	ans=max(ans,sum);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	bool flag1=0;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		if(a[i]!=a[i-1]+1){
			flag1=1;
		}
	}
	if(!flag1){
		long long s=0;
		for(long long i=1;i<=n;i++){
			if(s+i<=m){
				ans++;
				s+=i;
			}else{
				break;
			}
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<=n;i++){
		if(a[i]-a[i-1]>m){
			break;
		}
		num(i);
	}
	cout<<ans;
	return 0;
}
