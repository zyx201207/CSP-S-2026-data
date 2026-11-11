#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	int k[500005];
	long long x,b,ans;
	for(long long i=1;i<=n;++i){
		cin>>k[i];
	}
	sort(k+1,k+n+1);
	x=k[1];
	for(long long i=2;i<=n;++i){
		x+=k[i];
		b=x-i*k[i]+m;
		if(b>=0){
			ans=i;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
