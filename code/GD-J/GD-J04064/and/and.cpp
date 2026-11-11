#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000005],maxi,b;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	b=a[1];
	for(int i=2;i<=m;i++){
		b&=a[i];
	}
	cout<<b;
	return 0;
}
