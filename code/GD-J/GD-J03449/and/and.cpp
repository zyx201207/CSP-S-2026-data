#include<bits/stdc++.h>
using namespace std;
long long a[200005];
long long b[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];
		return 0;
	}else if(n==m){
		cout<<a[1];
		return 0;
	}else{
		cout<<a[n-m+1];
		return 0;
	}
}

