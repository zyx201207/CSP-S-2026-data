#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,n1[200001];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>n1[i];
	}
	sort(n1,n1+n);
	cout<<n1[n-m];
	return 0;
}
