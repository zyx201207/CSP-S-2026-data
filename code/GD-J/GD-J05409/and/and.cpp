#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
    freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,a[114514];
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1,cmp);
	long long k=a[1];
	for(int i=2;i<=m;i++) k&=a[i];
	cout<<k;
	return 0;
}
