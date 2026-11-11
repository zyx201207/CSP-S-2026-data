#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int nn[n+5];
	for(int i=1;i<=n;i++){
		cin>>nn[i];
	}
	sort(nn+1,nn+n+1);
	long long s=nn[n];
	for(int i=n-1;i>n-m;i--){
		s=s&nn[i];
	}
	cout<<s;
	return 0;
}