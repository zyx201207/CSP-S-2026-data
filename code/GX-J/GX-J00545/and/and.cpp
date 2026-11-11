#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
bool Test16_17=true;

int Out=0;
int b[200005];
bool vis[200005];
void dfs(int x) {
	if(x>m) {
		int Ans=2147483647;
		for(int i=1;i<=m;i++) Ans=Ans & a[b[i]];
		if(Ans>Out) Out=Ans;
		return;
	}
	for(int i=1;i<=n;i++) {
		if(vis[i]) continue;
		vis[i]=true;
		b[x]=i;
		dfs(x+1);
		vis[i]=false;
	}
	return;
}
int main() {
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		if(a[i]>=4) Test16_17=false;
	}
	sort(a+1,a+n+1);
	if(n<=20) {//test 1~5
		dfs(1);//DaBaoLi,TLE
		cout<<Out;
		return 0;
	}
	if(m==1) {//test 6
		cout<<a[n];
		return 0;
	}
	if(m==n) {//test 7
		int ans=INT_MAX;
		for(int i=1;i<=n;i++) ans&=a[i];
		cout<<ans;
		return 0;
	}
	if(m==2) {//test 8~10
		int ans=0;
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(i!=j && (a[i]&a[j])>ans) ans=(a[i]&a[j]);
		cout<<ans;
		return 0;
	}
	if(Test16_17) {//Test 16~17
		int Appear[4]={0};
		for(int i=1;i<=n;i++) Appear[a[i]]++;
		if(Appear[3]>=m) cout<<3;
		else if(Appear[2]>=m || (Appear[3]+Appear[2])>=m) cout<<2;
		else if(Appear[1]>=m || (Appear[3]+Appear[1])>=m) cout<<1;
		else cout<<0;
	}
	return 0;
}


/*
 * 6 2
 * 101 100 100 100 1001 10000
 * 
 * 1
 * */
