#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005];
//bool cmp(long long a,long long b){
//	return a>b;
//}
//long long max1,max2,max3;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	cout<<a[m];
	return 0;
}
//5 3
//31 3 1 15 7

