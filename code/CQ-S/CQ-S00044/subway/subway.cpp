#include<bits/stdc++.h>
using namespace std;
int t,n,m,d,p;
int c;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>t>>n>>m>>d>>p;
	for(int i=1;i<=m;i++){
		int x;
		cin>>x;
		c+=x;
	}
	for(int i=1;i<=n;i++){
		cout<<c;
	}
	return 0;
} 
