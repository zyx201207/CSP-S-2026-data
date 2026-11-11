#include<bits/stdc++.h>
using namespace std;
long long n,a[500005],cnt=0;
long long m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int k=ceil((double)(n/2))+1;
	sort(a+1,a+n+1);
	for(int i=k;i>=1;i--){
		if(m<a[k]-a[i])break; 
		a[i]=a[k];
		m-=(a[k]-a[i]);
	}
	for(int i=1;i<=n;i++){
		if(a[i]==a[k])cnt++;
	}
	cout<<cnt;
	return 0;
}
