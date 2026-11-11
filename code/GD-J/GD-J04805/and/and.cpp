#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
ll n,m,su,mx=-99;
ll a[N],ans=-1;
void dfs(ll t,ll sum,ll mm){
	if(mm>=m){
		ans=max(ans,sum);
		return;
	}
	if(t>n) return;
	dfs(t+1,(sum?sum:a[t])&a[t],mm+1);
	dfs(t+1,sum,mm);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
		if(i==1) su=a[i];
		else{
			su=su&a[i];
		}
	}
	if(m==1){
		cout<<mx;
		return 0;
	}
	if(m==n){
		cout<<su;
		return 0;
	}
	dfs(1,0,0);
	cout<<ans;
	return 0;
} 
