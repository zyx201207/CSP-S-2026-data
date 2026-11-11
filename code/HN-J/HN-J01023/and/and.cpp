#include<bits/stdc++.h>
using namespace std;
#define int long long

int a[1000010];
int b[1000010];
int c[1000010];
int d[1000010];
int e[1000010];
int vis[1000010];
int n,m;
int ans= -1e18;
void dfs(int x,int y,int t){
	if(y==m){
		ans=max(ans,t);
		return ;
	}
	for(int i=1; i<=n; i++){
		if(vis[i]==0){
			vis[i]=1;
			if(t==0){
				dfs(i,y+1,a[i]);
			}else{
				dfs(i,y+1,t&a[i]);
			}
			vis[i]=0;
		}
	}
}
bool check(int x){
	while(x!=0 && x%2==0){
		x/=2;
	}
	if(x==1 || x==0){
		return true;
	}
	return false;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int ma= -1e18,f=0;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		ma=max(ma,a[i]);
	}
	if(check(n)){
		cout<<n-1;
		return 0;
	}
	if(m==1){
		sort(a+1,a+n+1,greater<int>());
		cout<<a[1];
		return 0; 
	}else if(m==2){
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				if(i!=j){
					ans=max(a[i]&a[j],ans);
				}
			}
		}
		cout<<ans;
		return 0; 
	}else if(m==n){
		int ans=a[1];
		for(int i=2; i<=n; i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	if(n<=20){
		dfs(1,0,0);
		cout<<ans;
	}else if(ma<=4){
		int cnt=0,cnt1=0,cnt2=0,cnt3=0;
		for(int i=1; i<=n; i++){
			if(a[i]==3){
				b[++cnt]=a[i];
			}else if(a[i]==2){
				c[++cnt1]=a[i];
			}else if(a[i]==1){
				d[++cnt2]=a[i];
			}else{
				e[++cnt3]=a[i];
			}
		}
		if(cnt+cnt1>=m){
			cout<<2;
		}else if(cnt+cnt2>=m){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		sort(a+1,a+n+1,greater<int>());
		cout<<a[m]; 
	}
	return 0;
}
