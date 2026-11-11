#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200200],ans=0,k=0;
ll n,m,s=0;
void dfs(ll yi,ll ar,ll an){
	if(yi==m){
		ans=max(ans,an);
		return;
	}
	if(ar>n) return;
		if(yi==0) dfs(yi+1,ar+1,a[ar]);
		else dfs(yi+1,ar+1,an&a[ar]);
		dfs(yi,ar+1,an);
	
}
void bf1(){
	for(int i=1;i<=n;i++) ans=max(a[i],ans);
	return;
}
void bf2(){
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ans=max(ans,a[i]&a[j]);
		}
	}
	return;
}
void bfn(){
	ans=a[1];
	for(int i=2;i<=n;i++){
		ans&=a[i];
	}
	return;
}
void bfn2(){
	ans=0;
	return;
}
void tb(){
	ans=0;
	return;
}
void ta(){
	sort(a+1,a+n+1);
	ans=a[n-m+1];
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i){
			s=1;
		}
	}
	if(n<=20){
		dfs(0,1,0);
	}else{
		if(m==1){
			bf1();
		}else{
			if(m==2){
				bf2();
			}else{
				if(m==n){
					bfn();
				}else{
					if(m==n-1){
						bfn2();
					}else{
						if(s==0){
							tb();
						}else{
							ta();
						}
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
}
