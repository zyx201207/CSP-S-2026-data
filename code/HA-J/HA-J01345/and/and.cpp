#include<bits/stdc++.h>
using namespace std;
int A[1001];
int main(){
	freopen("and.in","r",stdin);
  	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a=A[0];
	for(int i=0;i<n;i++){
		cin>>A[i];
		a=max(a,A[i]);
	}
	cout<<a;
	return 0;
}
