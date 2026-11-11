#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500001];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(n<=5000){
		long long mx=-INT_MAX;
		for(long long i=1;i<=n;i++){
			long long tmp=m,cnt=1;
			for(long long j=i-1;j>=1;j--){
				if(tmp>=a[i]-a[j]){
					tmp-=(a[i]-a[j]);
					cnt++;
				}
			}
			for(long long j=i+1;j<=n;j++){
				if(a[j]==a[i]) cnt++;
			}
			mx=max(mx,cnt);
		}
		cout<<mx;
		return 0;
	}
	long long flag1=1;
	long long cha=a[2]-a[1];
	for(long long i=2;i<=n;i++){
		if(a[i]-a[i-1]!=cha){
			flag1=0;
		}
	}
	if(flag1==1){
		long long cnt=0;
		for(long long i=n;i>=1;i--){
			if(m>=a[n]-a[i]){
				cnt++;
				m-=(a[n]-a[i]);
			}
		}
		cout<<cnt;
		return 0;
	}
	long long flag=1;
	for(long long i=1;i<=n;i++){
		if(a[i]!=i){
			flag=0;
			break;
		}
	}
	if(flag==1){
		long long cnt=0;
		for(long long i=n;i>=1;i--){
			if(m>=a[n]-a[i]){
				cnt++;
				m-=(a[n]-a[i]);
			}
		}
		cout<<cnt;
	}else{
		cout<<n;
	}
	return 0;
}
