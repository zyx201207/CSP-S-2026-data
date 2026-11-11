#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+5;
long long a[N],b[N];
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n,k;cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=k;i++){
		b[i]=a[i];
	}
	long long ans=b[1];
	for(int i=2;i<=k;i++){
		ans&=b[i];
	}
	cout<<ans;
	return 0;
}
/*
4 2
3 15 12 12

5 3
31 3 1 15 7
*/
