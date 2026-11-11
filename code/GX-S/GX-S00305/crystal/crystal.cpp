#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,inf=0x3f3f3f3f;
int n,m;
int a[N];
int vis[N];
int sum,ans;
int xx,lx;
bool fA=1,fB=1;
int dc;
void dfs(int x){
	if(x<0){
		for(int i=1;i<=n;i++){
			if(vis[i]){
				lx+=a[xx]-a[i];
				sum++;
			}
		}
		if(lx<=m) ans=max(sum,ans);
		sum=0;
		lx=0;
		return;
	}
	vis[x]=1;
	dfs(x-1);
	vis[x]=0;
	dfs(x-1);
}
void tjh3(){
	sort(a+1,a+1+n);
	for (int i=n;i>0;i--){
		xx=i;
		dfs(i);
		for(int j=1;j<=n;j++) vis[j]=0;
	}
	cout <<ans;
	return;
}
void tjh1(){//A
	sort(a+1,a+1+n);
	int t=0;
	for(int i=2;i<=n;i++){
		t+=i-1;
		if(t>m){
			ans=i-1;
			break;
		}
	}
	cout <<ans;
	return;
}
void tjh2(){//B
	sort(a+1,a+1+n);
	int t=0;
	for(int i=2;i<=n;i++){
		t+=(i-1)*dc;
		if(t>m){
			ans=i-1;
			break;
		}
	}
	cout <<ans;
	return;
}
int main () {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >>n >>m;
	for (int i=1;i<=n;i++){
		cin >>a[i];
		if(a[i]!=i) fA=0;
		if(i==2) dc=a[i]-a[i-1];
		else if(i>=3 && a[i]-a[i-1]!=dc) fB=0;
	}
	if(fA) tjh1();
	else if(fB) tjh2();
	else tjh3();
	return 0;
}
