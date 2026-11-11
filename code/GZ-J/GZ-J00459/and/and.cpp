//GZ-J00459 凤冈县第四中学 李朋秦 
#include<bits/stdc++.h>
using namespace std;
int n,m,a[200001],max=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	sort(a+0,a+n);
	long long x=0;
	for(int i=n;i>=n-m;i--){
		int x1=a[i]&a[i-1];
		if(x1>x)x=x1;
	}
	cout<<x;
	return 0;
}
