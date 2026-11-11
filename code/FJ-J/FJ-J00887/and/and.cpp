#include<bits/stdc++.h>
using namespace std;
//I Love CCF Very Very Much!
const int N=2e5+500;
int n,m;
int a[N];
int cn1[N];
int cnt1(int n){
	int cnt=0;
	while(n){
		n&=(n-1);
		cnt++;
	}
	return cnt;
}
void solve1(){
	int ans=2147483647;
	for(int i=1;i<=n;i++){
		ans=ans&a[i];
	}
	cout<<ans;
}
void solve2(){
	int cnt=0;
	int ans=2147483647;
	int maxx=-1;
	for(int i=1;i<=n;i++){
		if(cn1[i]==1){
			maxx=max(maxx,a[i]);
			cnt++;
		}else{
			ans=ans&a[i];
		}
	}
	if(cnt>1){
		cout<<maxx;
	}else{
		cout<<ans;
	}
}
void solve3(){
	int mx=-2;
	for(int i=1;i<=n;i++){
		mx=max(mx,a[i]);
	}
	cout<<mx;
}
void solve4(){
	int mx=-1;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			mx=max(mx,a[i]&a[j]);
		}
	}
	cout<<mx;
}
int dfsmx=-1;
void dfs(int step,int ans,int i){
	if(step==m){
		dfsmx=max(dfsmx,ans);
	}
	dfs(step+1,ans&a[i],i+1);
	dfs(step,ans,i+1);
}
void solve6(){
	cout<<"I Love CCF Very Very Much!";
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cn1[i]=cnt1(a[i]);
	}
	if(n==m){
		solve1();
	}else if(m==n-1){
		solve2();
	}else if(m==1){
		solve3();
	}else if(m==2){
		solve4();
	}else if(n<=20){
		dfs(0,2147483647,1);
		cout<<dfsmx;
	}else{
		solve6();
	}
	return 0;
}
