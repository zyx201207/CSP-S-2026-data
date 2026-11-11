#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],maxl=-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}for(int i=1;i<=n;i++){
		maxl=max(a[i],a[i+1]);
	}cout<<maxl; 
	return 0;
}
