#include<bits/stdc++.h>
using namespace std;
long long n,ans,m,a[200005];
bool k(long long a,long long b){
	return a>b;
	}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,k);
	cout<<a[m];
	return 0;
}
