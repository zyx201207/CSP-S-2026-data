#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500055],b[500055],sum,cnt,ans;
bool cmp(long long x,long long y){
	return x<y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=2;i<=n;i++){
		b[i]=a[i]-a[i-1];
	}
	cnt=1;
	sum=0;
	ans=0;
	for(int i=2;i<=n;i++){
		if(sum+b[i]*cnt>m){
			cnt=1;
			sum=0;
		}else{
			sum=sum+b[i]*cnt;
			cnt++;
			ans=max(ans,cnt);
		}
	}
	cout<<ans;
	return 0;
}
