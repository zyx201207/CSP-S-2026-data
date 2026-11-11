#include<bits/stdc++.h>
using namespace std;
long long n,m;
int a[200005],maxx=-999,ansn;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
		ansn=ansn&&a[i];
	}
	if(m==1){
		cout<<maxx;
		return 0;
	}
	if(m==n){
		cout<<ansn;
		return 0;
	}
	cout<<maxx;
	return 0;
}
