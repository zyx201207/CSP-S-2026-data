#include<bits/stdc++.h>
using namespace std;
long long n,m,sum,ma,a[2005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			ma=max(ma,a[i]);
		}
		cout<<ma;
	}else if(m==n){
		sum=a[1];
		for(int i=2;i<=n;i++){
			sum=(sum & a[i]);
		}
		cout<<sum;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(a[i]!=a[j]) ma=max(ma,(a[i] & a[j]));
			}
		}
		cout<<ma;
	}
	sort(a+1,a+1+n);
	sum=a[n];
	for(int i=n-1;i>=n-m+1;i--){
		sum=(sum & a[i]);
	}
	cout<<sum;
	return 0;
}
