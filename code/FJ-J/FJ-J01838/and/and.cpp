#include<bits/stdc++.h>
using namespace std;
int n,m,a[10000001],maxn,max2;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(m==1){
		cout<<maxn;
	}
	return 0;
}

