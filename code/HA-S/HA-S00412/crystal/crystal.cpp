#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100005],t=0,u;
long long f[100005];
bool k=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		f[i]=a[i]+f[i-1];
	}
	u=a[2]-a[1];
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=u){
			k=0;
			break;
		}
	}
	if(k){
		long long s=0,i;
		for(i=1;i<=m;i++){
			s+=u*i;
			if(s>m){
				break;
			}
		}
		cout<<i;
		
		return 0;
	}
	long long ans=0;
	for(int i=n;i>=1;i--){
		t=a[i]*(i-1)-f[i-1];
		if(t<=m){
			ans=i;
			cout<<ans;
			return 0;
		}
	}
	cout<<ans;
	
	return 0;
}
/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
5 8
1 3 5 7 9
*/
