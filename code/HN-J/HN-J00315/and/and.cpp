#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200010],ans=0;
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1,cmp);
	cout<<a[m];
	return 0;
}
