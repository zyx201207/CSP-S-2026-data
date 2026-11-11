#include<bits/stdc++.h>
using namespace std;
int a[200005];
int n,m;
int maxn=-1;
void f(int x,int b,int sum){
	 if(b==m+1&&x!=0)return;
	 if(x==0)maxn=max(maxn,sum);
	 else{
		f(x-1,b+1,sum&a[b]);
		f(x,b+1,sum);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	f(m-1,2,a[1]);
	cout<<maxn;
	/*
	 void f(int x,int b,int sum){
	 * if(b==m+1&&x!=0)return;
	 if(a==0)maxn=max(maxn,sum);
	 * else{
	 * f(x-1,b+1,sum&a[b]);
	 * f(x,b+1,sum);
	 * 
	 */
	return 0;
}
