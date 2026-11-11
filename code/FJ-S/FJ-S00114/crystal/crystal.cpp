#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500010],s[500010];
long long check(long long s){
	int ss=0;
	for(int i=1;i<s;i++){
		ss+=a[s]-a[i];
	}
	return ss;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		//scanf("lld%",a[i]);
		cin>>s[i];
	}
	if(s[1]>s[2]){
		for(int i=1;i<=n;i++){
			a[i]=s[n-i+1];
		}
	}else{
		for(int i=1;i<=n;i++) a[i]=s[i];
	}
	for(int i=1;i<=n;i++) cout<<a[i]<<' ';
	long long res,l=1,r=n;
	while(l<=r){
		long long mid=(l+r)/2;
		long long tmp=check(mid);
		if(tmp<=m){
			res=mid;
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	cout<<res;
	return 0; 
}
