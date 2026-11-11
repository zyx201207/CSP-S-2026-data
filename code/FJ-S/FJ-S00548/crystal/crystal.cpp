#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[1000020];
long long b[1000020];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i]=a[i];
		b[i]+=b[i-1];
	}
	long long ans=0,cnt,l=1;
	for(cnt=1;cnt<=n;cnt++){
		while(b[cnt]-b[l-1]+m<a[cnt]*(cnt-l+1))l++;
		ans=max(ans,cnt-l+1);
	}
	cout<<ans;
}
/*
我要唐死我了
T1 58min 
*/
