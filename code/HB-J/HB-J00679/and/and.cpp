#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[200005],ji[100],o[200005];
bool cmp(int x,int y){
	return x>y;
}


signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	//for(int i=1;i<=n+1;i++){
	//	cout<<a[i]<<" ";
	//}
	sort(a+1,a+1+n,cmp);
	o[0]=2147483647;
	for(int i=1;i<=m;i++){
		//int cnt=z(a[i]);
		//cout<<cnt;
		o[i]=o[i-1]&a[i];
	}
	cout<<o[m];
	return 0;
}

