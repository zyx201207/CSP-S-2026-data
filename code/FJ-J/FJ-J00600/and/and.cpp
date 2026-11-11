#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ma=0;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		long long k=a[i];
		for(int j=1;j<m;j++){
			k&=a[i+j];
		}
		ma=max(ma,k);
	}
	cout<<ma;
	return 0;
}
