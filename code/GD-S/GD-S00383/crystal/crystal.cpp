#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long sum[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	int max_len=1;
	for(int i=2;i<=n;i++){
		long long cnt=a[i]*i-a[i]-sum[i-1];
		if(m>=cnt){
			max_len=i;
		}else{
			int l=1;
			while(cnt>m){
				cnt+=a[i]-a[l];
				l++;
			}
			max_len=max(i-l+1,max_len);
		}
	}
	cout<<max_len;
	return 0;
} 
