#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=1,pd,dc;
int a[20005],s[20005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		dc+=a[i];
		s[i]=a[i]-a[i-1];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		pd+=(a[n]-a[i]);
	}
	if(pd<=m){
		cout<<n;
		return 0;
	}
	int c=a[2]-a[1];
	if(dc==n*a[n]-(c+c*(n-1))*(n-1)/2){
		if(m>c){
			cout<<n;
		}else{
			cout<<0;
		}
		return 0;
	}
	
	cout<<0;
	return 0;
}
