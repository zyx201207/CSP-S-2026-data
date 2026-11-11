#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a=0,b=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a;
		b=max(a,b);
	}
	cout<<b;
}
