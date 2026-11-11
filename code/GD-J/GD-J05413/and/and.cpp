#include <bits/stdc++.h>
using namespace std;
int a[200005],b[35],c[200005];
int main(){
	freopen(and.in,"r",stdin);
	freopen(and.out,"w",stdout);
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if (n==1){
		cout<<a[1];
		return 0;
	}
	if (m==1){
		cout<<a[n];
		return 0;
	}
	int nm=0;
	for (int i=n;i>=1;i--){
		for (int j=1;j<=30;j++){
			b[j]=a[i]%2;
			a[i]/=2;
			if (a[i]==0){
				nm=j;
				break;
			}
		}
		for (int j=nm;j>=1;j--){
			c[i]*=10;
			c[i]+=b[j];
		}
		nm=0;
	}
	long long ans=0;
	long long num=c[n];
	for (int i=1;i<=m-1;i++){
		num&=c[n-i];
	}
	for (int i=1;i<=10;i++){
		if (num%10==1){
			ans+=pow(2,i);
		}
		num/=10;
		if (num==0)break;
	}
	cout<<ans;
	return 0;
}
