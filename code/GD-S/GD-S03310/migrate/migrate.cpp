#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,d;
	cin>>c>>d;
	while(d){
		d--;
		int n,m,ppp=0;
		cin>>n>>m;
		int a[n+1];
		for(int i=1;i<=n;i++){
		cin>>a[i];
	
		}
		sort(a+1,a+1+n);
		for(int i=1;i<=n-3;i++){
		if(a[i+3]-a[i]>m&&a[i+3]-a[i]<2*m)
		ppp++;
	}
	cout<<ppp<<endl;
} 
}
