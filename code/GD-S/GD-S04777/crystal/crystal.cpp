#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500005];
int ch[500005];
int n,m;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1,num=0,ans=0;
	for(int i=1;i<=n;++i){
		if(i!=1){
			num+=(a[i]-a[i-1])*(i-l);
		}
		while(num>m){
			num-=a[i]-a[l];
			++l;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}
