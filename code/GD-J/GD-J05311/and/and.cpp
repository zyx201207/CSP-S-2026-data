#include <bits/stdc++.h>
using namespace std;
bool cmp(int a, int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,ans;
	cin>>n>>m;
	int a[n+10];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	ans=a[0];
	for(int i=1;i<m;i++){
		ans &= a[i];
	}
	cout<<ans;
	return 0;
}

