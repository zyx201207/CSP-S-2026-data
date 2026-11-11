#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int  c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int a[m];
	int max=0;
	for (int i=0;i<m;i++){
		cin>>a[i];
		max=max+a[i];
	}
	cout<<max<<max/2;
	return 0;
} 
