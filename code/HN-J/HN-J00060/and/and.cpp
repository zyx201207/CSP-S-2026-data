#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005];
bool cmp(int a,int b){return a>b;}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	cout<<a[m];
	return 0;
} 
/*
游记？ 
关注Hamster_Emperor谢谢喵
这题竟然只是排序我还dp了好久气死我了 
*/ 
