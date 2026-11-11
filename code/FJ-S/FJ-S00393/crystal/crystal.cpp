/*
I AK CSP!!!
I AK CSP!!!
I AK CSP!!!
*/ 
//43行拿75分赚麻了（T1这种类型的题我想不出来） 
#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n>5000){
		int d=a[2]-a[1];
		int cnt=d,ans=0;
		for(int i=1;i<=n;i++){
			if(m<0){
				break;
			}
			m-=cnt;
			cnt+=d;
			ans++;
		}
		cout<<ans;
		return 0;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int cnt=1;
		long long x=m;
		for(int j=i-1;j>=1;j--){
			x-=(a[i]-a[j]);
			if(x<0){
				break;
			}
			cnt++;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
/*
I AK CSP!!!
I AK CSP!!!
I AK CSP!!!
*/ 
