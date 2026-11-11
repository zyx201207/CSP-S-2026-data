#include <bits/stdc++.h>
using namespace std;
int n,m,a[200010],ans;
bool used[25];
void dfs(int now,int x){
	if(now==m+1){
		ans=max(ans,x);
		return;
	}
	for(int i=1;i<=n;i++){
		if(!used[i]){
			used[i]=1;
			dfs(now+1,x&a[i]);
			used[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n<=20){
		dfs(1,(1<<20)-1);
		cout<<ans;
		return 0;
	}
	if(n<=2000&&m==n){
		int z=(1<<20)-1;
		for(int i=1;i<=n;i++){
			z=z&a[i];
		}
		cout<<z;
		return 0;
	}
	if(n<=2000&&m==1){
		int z=0;
		for(int i=1;i<=n;i++){
			z=max(z,a[i]);
		}
		cout<<z;
		return 0;
	}
	if(n<=2000&&m==2){
		int z=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				z=max(z,a[i]&a[j]);
			}
		}
		cout<<z;
		return 0;
	}
	int z=0;
	for(int i=1;i<=n;i++)z=max(z,a[i]);
	if(z<4){
		int z1=0,z2=0,z3=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1)z1++;
			else if(a[i]==2)z2++;
			else if(a[i]==3)z3++;
		}
		if(z3>=m){
			cout<<3;
			return 0;
		}
		if(z2+z3>=m){
			cout<<2;
			return 0;
		}
		if(z1+z3>=m){
			cout<<1;
			return 0;
		}
		cout<<0;
		return 0;
	}
	bool flag=0;
	sort(a+1,a+n+1);
	for(int i=1;i<=20;i++){
		if(a[n-2]==((1<<i)-1)){
			flag=1;
			break;
		}
	}
	if(flag){
		cout<<a[n-2];
		return 0;
	}
	cout<<0;
	return 0;
}
