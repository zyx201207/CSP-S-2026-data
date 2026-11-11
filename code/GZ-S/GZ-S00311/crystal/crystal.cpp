//GZ-S00311 遵义市第四中学 殷震博 
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
int n,ans=1;
ll m,a[N];
bool A=true;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	ll d;
	for(int i=0;i<n;++i){
		cin>>a[i];
		if(i==1)d=a[i-1]-a[i];
		if(i>1 && a[i-1]-a[i]!=d)A=false;
	}
	sort(a+0,a+n);
	if(A){
		ll o=a[1]-a[0];
		for(int i=1;i<n;++i){
			if(m-o*(1ll*i)*(1ll*(i+1))/2>=0)++ans;
			else break;
		}
		cout<<ans;
		return 0;
	}
	for(int i=1;i<n;++i){
		ll sum=m;
		int ans_i=1;
		for(int j=i-1;j>=0;--j){
			sum-=a[i]-a[j];
			if(sum>=0)++ans_i;
			else break;
		}
		ans=max(ans,ans_i);
	}
	cout<<ans;
	return 0;
}
