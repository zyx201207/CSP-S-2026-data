#include<bits/stdc++.h>
using namespace std;
int n,m,sum,maxx,maxxnum;
struct number{int cnt,num;}a[200005];
bool cmp(number a,number b){return a.cnt>b.cnt;}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].num;
		if(i==1)sum=a[i].num;
		else sum&=a[i].num;
		for(int j=0;j<=30;j++)if(a[i].num&(1<<j))a[i].cnt++;
		if(a[i].cnt>maxx){maxx=a[i].cnt;maxxnum=a[i].num;}
	}
	if(n==m){cout<<sum;return 0;}
	if(m==1){cout<<maxxnum;return 0;}
	sort(a+1,a+1+n,cmp);
	
	
	return 0;
} 
/*
4 2
3
15
12
12
*/ 
