#include<bits/stdc++.h>

using namespace std;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,a[200005]={},mid,sum=0,v=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	mid=n/2;
	for(int i=mid-1;i>=1;i--){
		if(a[i]==a[mid]) continue;
		else{
			while(a[i]<a[mid]){
				a[i]++;
				m--;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]==a[i+1] || a[i]==v){
			sum++;
			v+=a[i]+a[i+1];
		}
	}
	if(sum==0) cout<<0; 
	else cout<<sum+1;
	return 0;
}
