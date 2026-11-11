#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],op,ans; 
void qwe1(){
	int x=0;
	for(int i=1;i<=n;i++)x=max(x,a[i]);
	cout<<x;
	return;
}
void qwe2(){
	int x=a[1]&a[2];
	for(int i=1;i<=n;i++)
		for(int j=1;j<i;j++)x=max(x,a[i]&a[j]);
	cout<<x;
	return;
}
void qwe3(){
	int x=0,y;
	for(int i=1;i<+n;i++){
		for(int j=1;j<=n;i++){
			if(j!=i){
				y=a[j];
				break;	
			}
		}
		for(int j=1;j<=n;j++)if(j!=i)y&=a[j];
		x=max(x,y);
	}
	cout<<x;
	return;
}
void qwe4(){
	
	int x=a[1];
	for(int i=1;i<=n;i++)x&=a[i];
	cout<<x;
	return;
}
void qwe5(){
	int x=a[n];
	for(int i=n;i>n-m;i--)x&=a[i];
	cout<<x;
	return;
}
void dfs(int k,int deep,int x){
	if(deep==m){
		ans=max(ans,x);
		return;
	}
	dfs(k+1,deep,x);
	for(int i=k+1;i<=n;i++){
		if(deep==0)dfs(i,deep+1,a[i]);
		else dfs(i,deep+1,x&a[i]);
	}
	return;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=2;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i-1)op=1;
	}
	if(m==1)qwe1();
	else if(m==2)qwe2();
	else if(m==n-1)qwe3();
	else if(m==n)qwe4();
	else if(!op)qwe5();
	else if(n<=20){
		dfs(0,0,0);
		cout<<ans;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
