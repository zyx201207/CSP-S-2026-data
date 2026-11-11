#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
long long n,m,a[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+1+n);
	int ans=a[n],j=n-1;
	for(int i=1;i<m;i++){
		ans=ans&a[j];
		j--;
	}cout<<ans;
	return 0;
}
