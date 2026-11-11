#include<bits/stdc++.h>
using namespace std;

const int N=2e5+5;
int n,m,a[N];
bool f;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i-1)f=0;
	}
	if(f)cout<<n-m+1;
	sort(a+1,a+n+1);
	if(m%2==0)cout<<a[n-m-1];
	else cout<<a[n-m];
	return 0;
}

