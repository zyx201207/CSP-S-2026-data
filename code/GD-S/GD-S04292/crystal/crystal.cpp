#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],x,sum,ans,o;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	sum=a[1];
	ans=1;
	o=1;
	x=2;
	for(int i=2;i<=n;i++,x++){
		if(a[i]*(x-1)-sum<=m){
			ans=max(x,ans);
		}
		else{
			while(a[i]*(x-1)-sum>m&&o<i){
				x--;
				sum-=a[o++];
			}
		}
		ans=max(x,ans);
		sum+=a[i];
	}
	cout<<ans;
	return 0;
}
