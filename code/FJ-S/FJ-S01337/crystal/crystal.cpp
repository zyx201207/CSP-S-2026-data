#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	long long a[n+10];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	long long b[n+10];
	b[0]=0;
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	int len[40];
	len[0]=n;
	for(int i=1;i<=29;i++){
		len[i]=(len[i-1]+1)/2;
	}
	int le=n/2;
	for(int i=1;i<=29;i++){
		long long minu=9000000000000000000;
		for(int j=1;j<=n-le+1;j++){
			long long u=a[j+le-1]*le-(b[j+le-1]-b[j-1]);
			minu=min(minu,u);
		}
		if(len[i-1]==1 and minu<=m){
			cout<<le;
			return 0;
		}
		if(minu<=m){
			le+=len[i];
		}else{
			le-=len[i];
		}
		le=max(le,1);
		le=min(le,n);
	}
}
