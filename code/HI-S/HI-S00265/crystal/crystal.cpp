#include<bits/stdc++.h>
using namespace std;
long long a[510000],b[51000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,num=0,k=1;cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==1) {
		cout<<a[n];
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		if(m>=a[i]-a[i-1]) {
			m-=a[i]-a[i-1];
			a[i-1]=a[i];
			num++;
			k=i-1;
		}
		
	}
	if(a[k-1]==a[k]){
		num++;
	}
	cout<<num;
	return 0;
}
