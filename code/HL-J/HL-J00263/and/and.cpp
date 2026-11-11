#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200100];
long long maxn=-1,sum=1,sum2=1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
		sum&=a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		sum2&=a[i];
	}
	long long sum3=1;
	if(m==1)cout<<maxn;
	else if(m==n){
		cout<<sum;
	}
	else if(n==2){
		cout<<sum2;
	}
	else {
		for(int i=n;i>=n-m;i--)sum3&=a[i];
		cout<<sum3;
	}
	return 0;
}
