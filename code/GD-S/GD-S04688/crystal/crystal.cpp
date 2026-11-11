#include<bits/stdc++.h>
using namespace std;
long long a[1000005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	long long n,m,fA=1,fB=1,B,sum=0;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i) fA=0;
		if(i==2){
			B=a[i]-a[i-1];
			continue;	
		}
		if(a[i]-a[i-1]!=B) fB=0;
	}
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++){
		sum+=a[n]-a[i];
	}
	if(m>=sum){
		cout<<n;
		return 0;
	}
	if(fA==1){
		for(int i=n;i>=1;i--){
			if(m>=n-i){
				m-=n-i;
				a[i]=n;
			}
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]==n) cnt++;
		}
		cout<<cnt;
		return 0;
	}
	if(fB==0){
		for(int i=n;i>=1;i--){
			if(m>=B*(n-i)){
				m-=B*(n-i);
				a[i]=n;
			}
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]==n) cnt++;
		}
		cout<<cnt;
		return 0;
	}
	long long mx=0;
	for(long long i=a[1];i<=a[n];i++){
		long long mz=0,m1=m;
		for(long long j=n;j>=1;j--){
			if(m1<=0){
				break;
			}
			if(a[j]<i && m1>=i-a[j]){
				m1-=i-a[j];
				mz++;
//				continue;
			}
		}
		for(long long j=1;j<=n;j++){
			if(a[j]==i) mz++;
		}
		mx=max(int(mx),int(mz));
	}
	cout<<mx;
} 
