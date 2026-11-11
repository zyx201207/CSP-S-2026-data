#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define psb push_back
#define db double
const int N=2e5+5;
int n,m;
ull a[N];
ull ans=0;
void dfs(int x,ull cnt,int chosen){
	if(chosen==m){
		ans=max(ans,cnt);
		return;
	}
	if(x==n-1)return;
	if(m-chosen>n-x+1)return;
	for(int i=x;i<=n;i++){
		dfs(i+1,cnt&a[i],chosen+1);
		dfs(i+1,cnt,chosen);
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==1){
		for(int i=1;i<=n;i++)ans=max(ans,a[i]);
		cout<<ans;return 0;
	}
	if(m==2){
		ull cnt;
		for(int i=1;i<n;i++){
			cnt=a[i]&a[i+1];
			for(int j=i+2;j<=n;j++)cnt=max(cnt,a[i]&a[j]);
			ans=max(ans,cnt);
		}
		cout<<ans;return 0;
	}
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++)ans=ans&a[i];
		cout<<ans;return 0;
	}
	dfs(1,(ull)((1<<31)*1LL-1),0);
	cout<<ans;
return 0;}
//50,TLE
//01dfs(¼ôÖ¦)+spj(m=1/2/n)
