#include<bits/stdc++.h>
using namespace std;
const int maxn=2e6+10;
int n,m;
int a[maxn];
//vector<int> a;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==1) cout<<a[n];
	else cout<<a[n-m+1];
	return 0;
}


