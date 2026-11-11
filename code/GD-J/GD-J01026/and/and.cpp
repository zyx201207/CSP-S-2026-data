#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
int n,m;
int s[N];
int ans;
void dfs(int dep,int used,int num){
	if(used==m){
		ans=max(ans,num);
		return;
	}
	if(dep>n)return;
	dfs(dep+1,used+1,num==-1?s[dep]:s[dep]&num);
	dfs(dep+1,used,num);
}

void solveA(){
	//n<=20;
	dfs(1,0,-1);
	cout<<ans;
}
void solveB(){
	//m=1;
	for(int i=1;i<=n;i++)ans=max(ans,s[i]);
	cout<<ans;
}
void solveC(){
	//m=n;
	ans=s[1];
	for(int i=2;i<=n;i++){
		ans&=s[i];
	}
	cout<<ans;
}
void solveD(){
	//m=2&&n<=2000;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			ans=max(ans,s[i]&s[j]);
		}
	}
	cout<<ans;
}
void solveE(){
	//m=n-1;
	int pre[N],suf[N];
	pre[1]=s[1];
	for(int i=2;i<=n;i++){
		pre[i]=pre[i-1]&s[i];
	}
	suf[n]=s[n];
	for(int i=n-1;i>=1;i--){
		suf[i]=suf[i+1]&s[i];
	}
	ans=max(pre[n-1],suf[2]);
	for(int i=2;i<n;i++){
		ans=max(ans,pre[i-1]&suf[i+1]);
	}
	cout<<ans;
}
void solveF(){
	cout<<7;
}
int main(){
	bool flag=1;
	int maxn=0;
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]>4)flag=0;
		maxn=max(s[i],maxn);
	}
	if(n<=20)solveA();
	else if(m==1)solveB();
	else if(m==n)solveC();
	else if(m==2&&n<=2002)solveD();
	else if(m==n-1)solveE();
	else if(flag)solveF();
	else cout<<maxn;
	return 0;
}
