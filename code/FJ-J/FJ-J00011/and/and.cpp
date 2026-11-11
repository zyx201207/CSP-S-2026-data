#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+10;
ll n,m,a[N],ans,w,aaaa,t;
void dfs(ll i,ll step){
	if(step>m) return;
	for(ll j=i+1;j<=n;j++){
		t=t&a[j];
		dfs(j,step+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		w=max(a[i],w);
	}
	if(m==1){
		cout<<w;
		return 0;
	}
	if(m==2){
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	if(n<=2000){
		for(ll i=1;i<=n;i++){
			t=a[i];
			dfs(i,2);
		}
		cout<<t;
		return 0;
	}
	//B
	ans=a[n-m+1];
	for(int i=n-m+2;i<=n;i++){
		ans=ans&a[i];
	}
	cout<<ans;
	return 0;
}

