#include<bits/stdc++.h>
using namespace std;

int n,m,a[200005],max1;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		max1=max(max1,a[i]);
	}
	cout<<max1;
	return 0;
}
