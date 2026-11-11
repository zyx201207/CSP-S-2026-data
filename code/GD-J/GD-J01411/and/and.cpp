#include<bits/stdc++.h>
using namespace std;
using LL=long long;
const int N=2e5;
LL n,m,ma=0,d;
LL a[N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(n==m){
		cout<<0;
		return 0;
	}
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n,cmp);
	if(m==1){
		cout<<a[0];
		return 0;
	}
	for(int i=m-1;i<n-m+1;i++){
		ma=max(ma,a[i]&a[i+1]);
	}
	cout<<ma;
	return 0;
}
