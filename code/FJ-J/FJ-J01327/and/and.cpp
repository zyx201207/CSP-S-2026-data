#include<bits/stdc++.h>
using namespace std;

const int N=2e5+5;
int n,m,maxa=-1,h=-1,h2;
int a[N];
void dfs(int pos,int s,int ans){
	if(s>=m){
		maxa=max(ans,maxa);
		return;
	}
	if(ans<=maxa)	return;
	if((n-pos)<(m-s))	return;
	for(int i=pos+1;i<=n;i++){
		dfs(i,s+1,ans&a[i]);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1)	h2=a[i];
		h2&=a[i];
		h=max(h,a[i]);
	}
	if(m==1){
		cout<<h;
		return 0;
	}
	if(m==n){
		cout<<h2;
		return 0;
	}
	dfs(0,0,pow(2,31)-1);
	cout<<maxa;
	return 0;
}
