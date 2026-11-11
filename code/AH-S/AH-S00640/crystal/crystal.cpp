#include<bits/stdc++.h>
using namespace std;
long long n,m,a[600001],num,h=1,t=1,ans=1,calq;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	while(t<=n){
		ans=max(ans,t-h+1);
		if(h==t&&a[t+1]-a[t]>m){
			num=0;
			h++;
			t++;
		}
		if(num+(t-h+1)*(a[t+1]-a[t])<=m){
			num+=(t-h+1)*(a[t+1]-a[t]);
			calq+=a[t+1]-a[t];
			t++;
	}else{
		num-=calq;
		calq-=a[h+1]-a[h];
		h++;
	}
	}
	cout<<ans;
	return 0;
}
