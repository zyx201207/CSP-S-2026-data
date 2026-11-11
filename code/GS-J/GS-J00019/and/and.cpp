#include<bits/stdc++.h>
using namespace std;
int a[200010],n,m,ans1;
void dfs(int l,int k,int ans){
	if(l==n+1){
		if(k==m){
			ans1=max(ans,ans1);
		}
		return;
	}
	dfs(l+1,k,ans);
	dfs(l+1,k+1,ans&a[l+1]);
}
int main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int maxa=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxa=max(maxa,a[i]);
	}
	if(n<=20){
		dfs(0,0,(1<<30)-1);
		cout<<ans1;
		return 0;
	}
	if(n<=2000&&m==1){
		int ans2=0;
		for(int i=1;i<=n;i++){
			ans2=max(ans2,a[i]);
		}
		cout<<ans2;
		return 0;
	}
	if(n<=2000&&m==n){
		int ans3=a[1];
		for(int i=2;i<=n;i++){
			ans3&=a[i];
		}
		cout<<ans3;
		return 0;
	}
	if(n<=2000&&m==2){
		int ans4=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans4=max(ans4,a[i]&a[j]);
			}
		}
		cout<<ans4;
		return 0;
	}
	if(m==n-1){
		int ans5=0;
		for(int i=1;i<=n;i++){
			int cnt=(1<<30)-1;
			for(int j=1;j<=n;j++){
				if(i!=j)cnt&=a[j];
			}
			ans5=max(ans5,cnt);
		}
		cout<<ans5;
		return 0;
	}
	if(maxa<4){
		int a0=0,a1=0,a2=0,a3=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0)a0++;
			if(a[i]==1)a1++;
			if(a[i]==2)a2++;
			if(a[i]==3)a3++;
		}
		int ans6=0;
		if(a3>=m){
			ans6=max(ans6,3);
		}
		if(a2>=m){
			ans6=max(ans6,2);
		}
		if(a1>=m){
			ans6=max(ans6,1);
		}
		if(a3+a2>=m){
			ans6=max(ans6,2);
		}
		if(a3+a1>=m){
			ans6=max(ans6,1);
		}
		cout<<ans6;
		return 0;
	}
	return 0;
}
