#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[1000000];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll l=1,ans=0,ls=0,co=0,jz=0;//左右，答案，目前答案，花费，基准，数量 
	for(int i=1;i<=n;i++){
		if(i!=1){
			co+=(i-l)*abs(a[i]-a[i-1]);
		}
		ls++;
		while(co>m){
			co-=abs(a[i]-a[l]);
			ls--;
			l++;
		}
		ans=max(ans,ls);
//		cout<<l<<"->"<<i<<endl;
	}
	cout<<ans;
}
/*
5 5
1 2 4 8 9

*/
