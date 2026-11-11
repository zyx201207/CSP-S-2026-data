#include <bits/stdc++.h>
using namespace std;

bool cmp(int a,int b){
	return a>b;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("and5.in","r",stdin);
	freopen("and5.out","w",stdout);
	
	int n,m;
	int a[230000] = {0};
	long long ans = 0;
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n,cmp);
	ans = a[1];
	for(int i=1;i<m;i++) ans &= a[i];
	cout<<ans;
	
	return 0;
}


