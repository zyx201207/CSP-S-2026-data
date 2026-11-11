#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
ll m,ans=0;
ll a[100005],diff[100005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	diff[1]=0;
	ll sum_d = 0,t_d=0;
	for(int i=2;i<=n;i++){
		diff[i] = a[i]-a[i-1];
		sum_d += diff[i]*(i-1);
		if(sum_d<0)break;
		if(sum_d<t_d)break;
		if(sum_d<=m){
			if(i>ans)ans=i;
		}
		else break;
		t_d = sum_d;
	}
	cout<<ans;
	return 0;
} 
