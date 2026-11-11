#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+10;
const int M=3e5+10;
ll n,m;
ll a[N],ans[M];
ll st[M];
ll vis[M];
void func(int be){
	if(be==n){
		return;
	}
	for(int i=0;i<n;i++){
		st[i]=0;
		vis[i]=0;
	}
	ll cnt=0;
	for(int i=be;i<n;i++){
		if(!vis[a[i]]){
			st[cnt]=a[i];
			cnt++;
			vis[a[i]]=1;
		}
		else{
			while(st[cnt]!=a[i]){
				vis[st[cnt]]=0;
				st[cnt]=0;
				cnt--;
			}
			cnt++;
		}
	}
	for(int k=0;k<cnt;k++){
		ans[st[k]]++;
	}
	func(be+1);
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie();
	cout.tie();
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	func(0);
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}

