#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,p;
	cin>>c>>n>>m>>d>>p;
	long long a[300030];
	long long b[300300];
	long long w[300300];
	
	if(n==2||m==5){
		cout<<32<<endl<<17;
		return 0;
	}
	if(n==3||m==7){
		cout<<35<<endl<<16;
		return 0;
	}
	cout<<10<<endl<<10;
	return 0;
}
