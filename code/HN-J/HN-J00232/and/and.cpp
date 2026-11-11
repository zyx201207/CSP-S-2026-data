#include<bits/stdc++.h>
using namespace std;
int n,m,a[200020],ans=0,b[5];
void dfs(int x,int y,int z){
	if(z>=m){
		ans=max(ans,y);
		return ;
	}
	if(x>n){
		return ;
	}
	dfs(x+1,y,z);
	dfs(x+1,y&a[x],z+1);
}
int px(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	int f=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>=4){
			f=1;
		}
	}
	if(n<=20){
		dfs(1,INT_MAX,0);
		cout<<ans;
	}else if(m==1){
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
	}else if(m==n){
		ans=INT_MAX;
		for(int i=1;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;		
	}else if(m==2&&n<=5000){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,(a[i]&a[j]));
			}
		}
		cout<<ans;
	}else if(f==0){
		for(int i=1;i<=n;i++){
			b[a[i]]++;
		}
		if(b[3]>=m){
			cout<<3;
		}else if(b[2]+b[3]>=m){
			cout<<2;
		}else if(b[3]+b[1]>=m){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		sort(a+1,a+n+1,px);
		ans=INT_MAX;
		for(int i=1;i<=m;i++){
			ans&=a[i];
		}
		cout<<ans;
	}
	return 0;
}
