#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],book[200005]={0};
bool cmp(long long a,long long b){
	return a>b;
}
long long dfs(int i,long long h){
	if(i==0){
		return h;
	}
	long long d=0;
	for(int j=0;j<n;j++){
		if(book[j]==0){
			book[j]=1;
			d=max(d,dfs(i-1,h&a[j]));
			book[j]=0;
		}
	}
	return d;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	if(n>205) cout<<a[m-1];
	else{
		cout<<dfs(m,2147483647);
	}
	return 0;
}
//<jing feng>
//1 bai liu jia yi -- kao de quan hui
//2 bai du san ying -- meng de quan dui
//3 bai mu si cheng -- kao de bu hao jiu ba bie ren de fen tou guo lai
