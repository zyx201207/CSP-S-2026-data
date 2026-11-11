#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
long long n,m;
const int MAXN=10000005;
long long a[MAXN];
bool cmp(long long a,long long b){
	return a>b;
}
long long  ans=0;
int main(){
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	ans=a[1];
	sort(a+1,a+n+1,cmp);
	for(int i=2;i<=m;i++){
		ans&=a[i];
	}
	cout<<ans;
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
