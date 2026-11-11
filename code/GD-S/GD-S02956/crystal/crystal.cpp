#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long m;
long long a[500005];
long long s[500005]; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	s[1]=a[1];
	for(int i=1;i<=n;i++){
		if(i!=1){
		s[i]=s[i-1]+a[i];
		}
		if(a[i]*i-s[i]<=m){
			ans=max(ans,i);
		}
		else 
		{
			if(n<=5000){
		for(int j=1;j<=i;j++){
			s[i]-a[j];
			if(a[i]*(i-j)-s[i]<=m){
			ans=max(ans,i-j);
			break;
		}
		}
	}
		}
	}
	cout<<ans;
	return 0;
} 
