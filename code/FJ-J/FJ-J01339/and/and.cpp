#include <bits/stdc++.h>
using namespace std;
int a[200005];
char c[200005];
int awy(int x){
	return (x&262143);
}
int cmp(int x,int y){
	return awy(x)<=awy(y);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n,s=0;
	cin>>m>>n;
	for(int i=1;i<=m;i++)cin>>a[i];
	sort(a+1,a+m+1,cmp);
	s=a[m];
	for(int i=m-1;i>m-n;i--)s=(s&a[i]);
	cout<<s;
	return 0;
} 
