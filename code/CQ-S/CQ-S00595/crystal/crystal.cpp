#include<bits/stdc++.h>
using namespace std;
long long a[500005];
long long b[500005];
long long n,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		b[i-1]=(a[i]-a[i-1]);
	}
	long long cnt=-1;
	long long ans,o;
	for(int i=1;i<=n;i++){
		ans=0;
		o=1;
		for(int j=i;j<n;j++){
			if(ans+o*b[j]>m) break;
			ans+=o*b[j];
			o++;
		} 
		cnt=max(cnt,o);
	}
	cout<<cnt;
	return 0;
} 
