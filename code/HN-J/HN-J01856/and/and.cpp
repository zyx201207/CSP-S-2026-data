#include<bits/stdc++.h>
using namespace std;
int n,m;
int a,b=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a;
		b=max(a,b);
	}
	cout<<b;
	return 0;
} 
