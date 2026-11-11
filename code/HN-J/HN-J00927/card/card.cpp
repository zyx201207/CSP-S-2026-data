#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N=5e5+5,M=3e5+5;
ll n,m,a[N],b[N],vis[M];
void sp(ll i){
	while(i++){
		if(b[i]==0){
			break;
		}
		b[i]=0;
	}
	return;
}
void f(int k){
	bool flag=false;
	ll j;
	for(int i=1;i<k;i++){
		if(b[i]==a[k]){
			flag=true;
			j=i;
			break;
		}
	}
	if(flag){
		sp(j);
	}else{
		b[k]=a[k];
	}
	if(k==n){
		for(int i=1;i<=n;i++){
			if(b[i]){
				vis[b[i]]++;
			}
		}
		b[k]=0;
		return;
	}
	f(k+1);
	b[k]=0;
	return;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		f(i);
	}
	for(int i=1;i<m;i++){
		cout<<vis[i]<<" ";
	}
	cout<<vis[m];
	return 0;
}
