#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m,a[N];
int ans=(1<<30)-1,maxn;
int p[N],q[N],cnt[5];
bool flag1=1,flag2=1,flag3=1;
bool check(int x){
	int lg=log(x);
	return ((1<<lg)==x);
}
void dfs(int k,int num,int sum){
	if(sum<=maxn) return;
	if(num==m){
		maxn=max(maxn,sum);
		return;
	}
	for(int i=k+1;i<=n;i++){
		dfs(i,num+1,sum&a[i]);
	}
}
int main(){
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(!check(a[i]+1))flag1=0;
		if(a[i]!=i-1)flag2=1;
		if(a[i]>4)flag3=0;
	}
	if(m==1){
		for(int i=1;i<=n;i++)
			maxn=max(maxn,a[i]);
		cout<<maxn;
	}else if(m==2){
		for(int i=1;i<=n;i++)
			for(int j=1;j<i;j++)
				maxn=max(maxn,a[i]&a[j]);
		cout<<maxn;
	}else if(m==n){
		for(int i=1;i<=n;i++)
			ans&=a[i];
	}else if(m==n-1){
		p[0]=q[n+1]=((1<<30)-1);
		for(int i=1;i<=n;i++)
			p[i]=p[i-1]&a[i];
		for(int i=n;i>=1;i--)
			q[i]=q[i+1]&a[i];
		for(int i=1;i<=n;i++)
			maxn=max(maxn,p[i-1]&p[i+1]);
		cout<<maxn;
	}else if(flag1){
		sort(a+1,a+1+n,greater<int>());
		for(int i=1;i<=n;i++)
			ans&=a[i];
		cout<<ans;
	}else if(flag3){
		for(int i=1;i<=n;i++)
			cnt[a[i]]++;
		int nm=m-cnt[3];
		if(cnt[4]==n)cout<<4;
		else if(n<1)cout<<3;
		else if(cnt[2]>=nm)cout<<2;
		else if(cnt[1]>=nm)cout<<1;
		else cout<<0;
	}else if(n>2000&&n<=200000&&check(n)&&flag2){
		sort(a+1,a+1+n,greater<int>());
		for(int i=m;i>=1;i++)
			ans&=a[i];
		cout<<ans;
	}else{
		sort(a+1,a+1+n,greater<int>());
		dfs(0,0,(1<<30)-1);
		cout<<maxn;
	}
	return 0;
}
