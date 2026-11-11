#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	long long a,c[200005],maxx=0,x;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a;
		c[i]=a;
	}
	for(int i=1;i<=n-m+1;i++){
		x=c[i];
		for(int j=i+1;j<=i+m-1;j++){
			x^=c[i+1];
		}
		if(x>maxx){
			maxx=x;
		}
	}
	cout<<maxx;
	return 0;
} 
