#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,m,a[N],b[N],ans=0;
bool cmp(int a,int b){
	int ta=__builtin_popcount(a),tb=__builtin_popcount(b);
	return ta>tb;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i],b[i]=a[i];
	sort(a,a+n,cmp);
	sort(b,b+n);
	if(m==1||n==1){
		cout <<b[n-1];
		return 0;
	}
	ans=a[0];
	for(int i=1;i<m;i++) ans=ans&a[i]; 
	cout <<ans;
	return 0;
}
