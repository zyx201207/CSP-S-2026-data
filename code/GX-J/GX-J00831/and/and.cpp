#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,inf=0x3f3f3f3f;
int vis[N];
int n,m;
int a[N];
int sum,ans=-1;
int l;
bool f=1;
int awy(int x,int y){
	int tjh=0;
	int j=1;
	for(int i=1;x>0 && y>0;i++){
		if(x%2==1 && y%2==1){
			tjh+=j;
		} 
		x/=2;
		y/=2;
		j*=2;
	}
	return tjh;
}
void dfs(int x){
	if(x>n){
		for (int i=1;i<=n;i++){
			if(vis[i]){
				l++;
				if(sum==0) sum=a[i];
				else {
					sum=awy(sum,a[i]);
					//cout <<sum <<" ";
				}
			}
		}
		if(l==m){
			ans=max(ans,sum);
			//cout <<sum <<" ";
		}
		l=0;
		sum=0;
		return;
	}
	vis[x]=1;
	dfs(x+1);
	vis[x]=0;
	dfs(x+1);
}
void tjh1(){//m==n-1
	int sum=0;
	for (int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) continue;
			if(sum==0) sum=a[j];
			else sum=awy(sum,a[j]);
		}
		ans=max(ans,sum);
		sum=0;
	}
	cout <<ans;
	return;
}
void tjh2(){//ai<4
	int x2=0,x3=0;
	for (int i=1;i<=n;i++){
		if(a[i]==2) x2++;
		if(a[i]==3) x3++;
	}
	if(x3>=m) cout <<3;
	else if(x3+x2>=m) cout <<2;
	else cout <<1;
	return;
}
void tjh3(){
	dfs(1);
	cout <<ans;
	return;
}
void tjh4(){//m==1
	for (int i=1;i<=n;i++)
		ans=max(a[i],ans);
	cout <<ans;
	return;
}
void tjh5(){//n==m
	ans=a[1];
	for (int i=2;i<=n;i++){
		ans=awy(ans,a[i]);
	}
	cout <<ans;
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >>n >>m;
	for (int i=1;i<=n;i++){
		cin >>a[i];
		if(a[i]>4) f=0;
	}
	if(m==1) tjh4();
	else if(m==n) tjh5();
	else if(m==n-1) tjh1();
	else if(f) tjh2();
	else tjh3();
	//cout <<awy(n,m);
	return 0;
}
