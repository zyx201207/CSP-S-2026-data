#include<bits/stdc++.h>

using namespace std;

const long long N=5e5+10;
long long n,m,ans=1,a[N],s[N];

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(long long i=2;i<=n;i++){
		for(long long j=i-ans;j>=1;j--){
			if(a[i]*(i-j)-s[i-1]+s[j-1]<=m) ans=i-j+1;
			else break; 
		}
	}
	cout<<ans;
	return 0;
}

