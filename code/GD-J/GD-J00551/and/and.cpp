#include<bits/stdc++.h>
using namespace std;
int a[114514];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n,greater<int>());
	cout<<a[1];
}
