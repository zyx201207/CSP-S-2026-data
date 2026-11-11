#include<bits/stdc++.h>
using namespace std;
long long a[600000];
long long diff[600000];
long long ans=0;
bool ok=true;
bool okk=true;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(long long i=1;i<n;i++){
		 diff[i]=(long long)a[i]-a[i-1];
		 if(diff[i]>1)ok=false;
		 if(i>=2 and diff[i]!=diff[i-1]){
		 	okk=false;
		 }
	}
	if(ok){
		if(m>=n)cout<<n;
		return 0;
	}
	if(okk){
		if(m>=(n-1)*diff[1])cout<<n;
		return 0;
	}
	sort(diff+1,diff+n+1);
	for(long long i=1;i<n;i++){
		if(m>=diff[i]){
			m-=diff[i];
			ans++;
		}
	}
	cout<<ans;
	return 0;
} 
