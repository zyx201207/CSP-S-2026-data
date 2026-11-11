#include<bits/stdc++.h>
using namespace std;
const long long N =514114;
long long n,m,a[N],h,t,c,ans;//head tail
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	h=1;
	t=1;
	ans=1;
	while (1){
		if(c<=m){
			ans=max(ans,t-h+1);
			if(t!=n)t++;
			else break;
			c+=(t-h)*(a[t]-a[t-1]);
		}else{
			c-=a[t]-a[h];
			h++;
		}
	}
	cout<<ans;
	return 0;
}
