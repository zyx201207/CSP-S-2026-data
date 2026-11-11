#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=2e5+5;
ll n,m,a[N],ans,vis[N],sum;
ll f(int x,int i,int j){
	ll sum1=sum;
	sum=sum&x;
	if(i==m){
		return sum;
	}
	vis[j]=1;
	ll cnt=0;
	for(int k=1;k<=n;k++){
		if(!vis[k]){
			cnt=max(cnt,f(a[k],i+1,k));
		}
	}
	sum=sum1;
	return cnt;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
  	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		sum=a[i];
		ans=max(f(a[i],1,i),ans);
	}
	cout<<ans;
	return 0;
}
