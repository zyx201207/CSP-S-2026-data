#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m,a[N];
int ans;
int vis[30];
int cnt=0;
int f[50];
void dfs(int x){
	if(x>n){
		if(cnt!=m) return;
		int o=0;
		int sum=0;
		for(int i=1;i<=n;i++){
			if(!vis[i]) continue;
			o++;
			if(o==1) sum=a[i];
			else{
				sum=sum&a[i];
			}
		}
		ans=max(ans,sum);
		return ;
	}
	vis[x]=1;cnt++;
	dfs(x+1);
	vis[x]=0;cnt--;
	dfs(x+1);
}
void solve1(){
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ans=max(ans,a[i]&a[j]);
		}
	}
}
bool flag1=true;
bool check(int x){
	for(int i=1;i<=30;i++){
		if(x==f[i]-1){
			return true;
		}
	}
	return false;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int spc6=-1,spc7=0;
	f[0]=1;
	for(int i=1;i<=30;i++){
		f[i]=f[i-1]*2;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1){
			spc7=a[i];
		}
		else{spc7=spc7&a[i];}
		spc6=max(spc6,a[i]);
		if(flag1){
			if(!check(a[i])){
				flag1=false;
			}
		}
	}
	if(n<=20){
		dfs(1);
		cout<<ans;
	}else if(n<=2000 and m==1){
		cout<<spc6;
	}else if(n<=2000 and n==m){
		cout<<spc7;
	}else if(n<=2000 and m==2){
		solve1();
		cout<<ans;
	}else if(flag1){
		sort(a+1,a+1+n);
		cout<<a[n-m+1];
	}else{
		cout<<0;
	}
	return 0;
}
