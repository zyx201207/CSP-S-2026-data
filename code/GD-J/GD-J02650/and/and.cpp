#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+7;
int n,m,ans;
int a[N];
int w[N];//2^i
void dfs(int t,int sum,int cnt){
	if(t==n+1){
		if(cnt==m) ans=max(ans,sum);
		return ;
	}
	if(cnt==0) dfs(t+1,a[t],cnt+1);
	if(cnt<m) dfs(t+1,sum&a[t],cnt+1);
	dfs(t+1,sum,cnt);
	return;
}
void ck(int k){
	int t=0;
	while(k){
		if(k&1) w[t]++;
		t++;
		k/=2;
	}
	return ;
}
bool cmp(int x,int y){
	return y>x;
}
bool cka(){
	for(int i=1;i<=n;i++){
		int fl=0;
		for(int p=1;p<=1<<20;p<<=1) if(p-a[i]==1) fl=1;
		if(!fl) return false;
	}
	return true;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n<=20){
		dfs(1,0,0);
		cout<<ans;
		return 0; 
	}
	if(m==1){
		for(int i=1;i<=n;i++) ans=max(ans,a[i]);
		cout<<ans;
		return 0;
	}
	if(m==n){
		ans=a[1];
		for(int i=1;i<=n;i++) ans=ans&a[i];
		cout<<ans; 
		return 0;
	}
	if(m==2){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==n-1){
		for(int i=1;i<=n;i++) ck(a[i]);
		int p=pow(2,20);
		bool fl=0;
		for(int i=20;i>=0;i--){
			if(w[i]==n) ans+=p;
			if(w[i]==n-1&&!fl) fl=1,ans+=p;
			p/=2;
		}
		cout<<ans;
		return 0;
	}
	if(cka()){
		sort(a+1,a+1+n,cmp);
		cout<<a[m];
		return 0;
	}
	int o=log2(n);
	if(o==log2(n)){
		for(int p=1,t=0;t<log2(n);p<<=1,t++){
			if(m<=p) ans+=p;
		}
		cout<<ans;
		return 0;
	}
	int mm=0;
	for(int i=1;i<=n;i++) mm=max(mm,a[i]);
	if(mm<=4){
		int op[5]={0};
		for(int i=1;i<=n;i++) op[a[i]]++;
		if(m<=op[4]) cout<<4;
		else if(m<=op[3]) cout<<3;
		else if(m<=op[2]+op[3]) cout<<2;
		else if(m<=op[1]+op[3]) cout<<1;
		else cout<<0;
		return 0;
	}
	cout<<0;
	return 0;
}
