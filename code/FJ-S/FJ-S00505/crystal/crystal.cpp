





#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
const int INF=1e12+5;
long long n,m;
long long a[N];
long long ans=-1;
bool check1(){
	long long gc=a[2]-a[1];
	for(int i=3;i<=n;i++){
		if(a[i-1]+gc!=a[i]){
		return 0;
		}
	}
	return 1;
}
void solve(){
	long long sum=0;
	for(int i=1;i<=n;i++){
		sum=sum+a[i];
		if(a[i]*i>m+sum){
			cout<<i-1;
			return ;
		}
	}
	cout<<n;
	return ;
}
int main(){
freopen("crystal.in","r",stdin);
freopen("crystal.out","w",stdout);
ios::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);
cin>>n>>m;
for(int i=1;i<=n;i++){
	cin>>a[i];
}
if(check1()){
	solve();
	return 0;
}
sort(a+1,a+n+1);
long long sum=0;
long long l=1,r=1;
while(r<=n){
	sum=sum+a[r];
	r++;
while((r-l)*a[r-1]-sum>m&&l<r){
sum=sum-a[l];
l++;
}
ans=max(ans,r-l);
//cout<<l<<" "<<r<<" "<<sum<<" "<<(r-l)*a[r-1]-sum<<"\n";
}
cout<<ans;
return 0;
}
