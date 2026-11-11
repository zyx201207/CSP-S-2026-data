#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,p=1,num=0,ans=0,a[500001];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		num+=(i-p)*(a[i]-a[i-1]);
		while(num>m){
			num-=a[i]-a[p++];
		}
		ans=max(ans,i-p+1);
	}
	cout<<ans;
	return 0;
}
