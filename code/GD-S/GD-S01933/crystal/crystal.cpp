#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],pre[500005],ans=1;
long long get(long long l,long long r){
	return a[r]*(r-l)-pre[r-1]+pre[l-1];
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)pre[i]+=a[i]+pre[i-1];
	for(long long r=2,l=1;r<=n;r++){
		while(get(l,r)>m&&l<r)l++;
		ans=max(ans,r-l+1);
	}
	cout<<ans;
} 
