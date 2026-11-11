#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;

int n,m,a[N];
bool vis;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i-1) vis=1;
	}
	sort(a+1,a+n+1);
	cout<<a[n-2];
	return 0;
}
