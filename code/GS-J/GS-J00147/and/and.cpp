#include<bits/stdc++.h>
using namespace std;
int a[10000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,maxXX=-1;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		maxXX=max(a[i],maxXX);
	}
	cout<<maxXX;
	return 0;
}
