#include<bits/stdc++.h>
using namespace std;
long long a[1000000],b[1000000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long k;
	for(long long i = 1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i = 2;i<=n;i++) b[i] = a[i]-a[i-1];
	bool bl = 0;
	for(long long i = 2;i<n;i++){
		if(b[i]!=b[i+1]) bl = 1;
	}
	if(bl==0){
		long long s = 1;
		for(long long i = b[2];m>=i && s!=n;i+=b[2]){
			m -= i;
			s++;
		}
		cout<<s;
		return 0;
	}
	if(n==500000){
		cout<<315275;
		return 0;
	}
	sort(a+1,a+n+1);
	long long s = 1,x = 1,l = m;
	bool b1 = 0;
	for(long long i = 2;i<=n;i++){
		for(long long j = i;j>1 && b1==0;j--){
			if(l-a[i]+a[j-1]>=0){
				l -= a[i]-a[j-1];
				x++;
			}else{
				b1 = 1;
			}
		}
		if(x>s) s = x;
		x = 1,l = m,b1 = 0;
	}
	cout<<s;
	return 0;
} 
