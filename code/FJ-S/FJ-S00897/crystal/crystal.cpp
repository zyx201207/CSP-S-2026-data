#include<bits/stdc++.h>
using namespace std;
long long a[500005],b[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	long long l=1,ans=0;
	for(int i=1;i<=n;i++){
		long long nw=a[i]*(i-l+1);
		nw-=m;
		while(nw>b[i]-b[l-1] && l<i){
			l++;
			nw-=a[i];
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
} 
/*
5 5
1 2 4 8 9

//*/
