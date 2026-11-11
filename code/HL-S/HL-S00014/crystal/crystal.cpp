#include<bits/stdc++.h>
using namespace std;
const int N=500005;
long long n,m;
long long a[N],s[N];
int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	long long mx=0;
	long long op=0;
	for(int i=2;i<n;i++){
		if(a[i]-a[i-1] == a[i+1]-a[i]){
			op++;
		}
	}
	if(op==n-2){
		long long sum=0,cnt=1,p=1;
		while(sum<m){
			if(sum+p*(a[2]-a[1])<=m){
				cnt++;
				sum=sum+(a[2]-a[1])*p;
				p++;
			}else{
				break;
			}
		}
		cout<<cnt;
		return 0;
	}
	if(n<=5000){
		for(int i=1;i<=n;i++){
			long long sum=0,cnt=0;
			for(int j=i;j>=1;j--){
				if(sum+a[i]-a[j]<=m){
					sum+=(a[i]-a[j]);
					cnt++;
				}
			}
			if(cnt>=mx) mx=cnt;
		}
		cout<<mx<<endl;
	}else{
		for(int i=1;i<=n;i++){
			s[i]=s[i-1]+a[i];
		}
		int	j=n;
		for(int i=n;i>=1;i--){
			long long sum=0;
			while(j>=1 && j<=i){
				sum=1ll*(i-j+1)*a[i]-1ll*(s[i]-s[j-1]);
				if(sum<m) j--;
				else break;
			}
			if(j==0){
				if(i-j>=mx) mx=i-j;
			}else if(1+i-j>=mx){
				mx=1+i-j;
			}
		}
		cout<<mx-1<<endl;		
	}
	
	return 0;
}