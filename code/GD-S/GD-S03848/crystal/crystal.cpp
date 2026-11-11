#include<bits/stdc++.h>
using namespace std;
long long n,m,s[500005],a[500005];

bool check(int xx){
	for(int i=xx;i<=n;i++){
	
		if(a[i]*xx-(s[i]-s[i-xx])<=m )return true;
	}
	return false ;
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
	int l=1,r=n;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid))l=mid+1;
		else r=mid-1;
	}
	cout<<r;
	return 0;
}

