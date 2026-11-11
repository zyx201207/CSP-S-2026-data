#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pq priority_queue
#define st stack
#define qu queue
#define qwq ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define N 200005
ll n=0,m=0;
ll a[N]={0};
//从数组a的第c+1位开始选b个数字，求这b个数与ans按位与的最大值 
ll dfs(ll b,ll c,ll ans){
	if(b==0){
		return ans;
	}
	if(c==n&&b>0){
		return 0;
	}
	ll maxx=ans&dfs(b-1,c+1,a[c+1]);
	for(ll i=c+2;i<=n;i++){
		maxx=max(maxx,ans&dfs(b-1,i,a[i]));
	}
	return maxx;
}
bool cmp(ll a,ll b){
	return a>b;
}
int main(){
	qwq;
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	ll maxx=0,myand=0,b=1;
	ll c[5]={0};
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
		if(a[i]>4){
			b=0;
		}else{
			c[a[i]]++;
		}
		if(i==1){
			myand=a[1];
		}else{
			myand=myand&a[i];
		}
	}
	if(m==1){//6 
		cout<<maxx<<endl;
	}else if(m==n){//7 
		cout<<myand<<endl;
	}else if(b==1){//16,17
		if(c[3]>=m){
			cout<<3<<endl;
		}else if(c[3]+c[2]>=m){
			cout<<2<<endl;
		}else if(c[3]+c[1]>=m){
			cout<<1<<endl;
		}else{
			cout<<0<<endl;
		}
	}else if(n>2000){//13
		sort(&a[1],&a[n+1],cmp);
		ll ans=a[1];
		for(ll i=2;i<=m;i++){
			ans=ans&a[i];
		}
		cout<<ans<<endl;
	}else{//1~5 8~10
		ll maxx=0;
		for(ll i=1;i<=n;i++){
			maxx=max(maxx,dfs(m-1,i,a[i]));
		}
		cout<<maxx<<endl;
	}
	return 0;
}
// 10 4
// 3 7 15 31 63 2047 4095 7 15 127
