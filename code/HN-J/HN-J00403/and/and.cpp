#include<bits/stdc++.h>
using namespace std;
long long n,m,a[250081],vis[250081],ans;
void a1(){
	long long ans1=0;
	for(long long i=1;i<=n;i++){
		ans1=max(ans1,a[i]);
	}
	cout<<ans1;
	return;
}
void a2(){
	long long ans1=0;
	for(long long i=1;i<=n;i++){
		for(long long f=i+1;f<=n;f++){
			ans1=max(ans1,a[i]&a[f]);
		}
	}
	cout<<ans1;
	return;
}
void D(long long step,long long now){
	if(step==m){
		ans=max(ans,now);
		return;
	}
	for(long long i=1;i<=n;i++){
		if(!vis[i]){
			vis[i]=1;
			D(step+1,now&a[i]);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==1){
		a1();
		return 0;
	}
	if(m==2){
		a2();
		return 0;
	}
	for(long long i=1;i<=n;i++){
		vis[i]=1;
		D(1,a[i]);
		vis[i]=0;
	}
	cout<<ans;
	return 0;
}
