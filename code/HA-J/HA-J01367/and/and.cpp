#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200005],t[200005];
//int pow_(int a){
//	int sum=1;
//	while(a--)sum*=2;
//	return sum;
//}
//inline int qp(int a,int b){
//	int res=0;
//	while(b){
//		if(b&1)res=res*a;
//		a=a*a;
//		b>>=1;
//	}
//	return res;
//}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	int cnt=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt=cnt&a[i];
	}
	int maxn=INT_MAX;
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
	}
	else cout<<'0';
	return 0;
}
