//GZ-J00071 张世铠 贵阳市白云区华师一学校 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200005];
bool vis[25];
ll mx=INT_MIN;
ll n,m,maxx=INT_MIN,all;
void dfs(ll num,ll ans){
	if(num==m){
		mx=max(mx,ans);
	}
	else {
		for(int i=1;i<=n;i++){
			if(vis[i]==0){
				vis[i]=1;
				dfs(num+1,ans&a[i]);
				vis[i]=0;
			}
		}
	}
}
bool __13(ll s){
	while(s!=1){
		if(s%2==0){
			return 0;
		}
		s/=2;
	}
	return 1;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	bool _13=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1){
			all=a[i];
		}
		else{
			all=(all&a[i]);
		}
		maxx=max(a[i],maxx);
		if(!__13(a[i])){
			_13=0;
		}
	}
	if(_13==1){
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
		return 0;
	}
	if(m==1){
		cout<<maxx;
		return 0;
	}
	if(m==n){
		cout<<all;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				mx=max(mx,(a[i]&a[j]));
			}
		}
		cout<<mx;
		return 0;
	}
	dfs(0,INT_MAX);
	cout<<mx;
	return 0;
}
