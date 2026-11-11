#include<bits/stdc++.h>
using namespace std;
long long a[500010],m,n,l,r,mid,k,s[500100],ans;
long long find(long long ll){
	long long p=1,q=n,md;
	md=(p+q)/2;
	while(p<q){
		if(a[md]<=ll)p=md+1;
		else q=md;
		md=(p+q)/2; 
	}
	return md;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	l=0;
	for(int r=1;r<=n;r++){
		if(a[r]*(r-l)-(s[r]-s[l])<=m)ans=max(ans,r-l);
		else l++;
	}
	cout<<ans;
	return 0;
}
