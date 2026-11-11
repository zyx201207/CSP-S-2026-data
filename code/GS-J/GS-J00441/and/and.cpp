#include<bits/stdc++.h>
using namespace std;
int n,m,a[10000000];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(i==(n-1)){
			cout<<a[i];
			return 0;
		}
	}
	return 0;
}
