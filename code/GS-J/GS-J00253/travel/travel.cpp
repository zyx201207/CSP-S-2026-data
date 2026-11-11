#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	for(int i=0;i<1;i++){
		if(a[i]!=c[i]&&b[i]==d[i+1]||b[i]==d[i-1]){
			cout<<0000;
		}else if(a[i]!=c[i]&&b[i]!=d[i+1]||b[i]!=d[i-1]){
			cout<<1000;
		}else if(b[i]==d[i+1]||b[i]==d[i-1]&&a[i]==c[i]){
			cout<<1111;
		}else if(b[i]!=d[i+1]||b[i]!=d[i-1]&&a[i]==c[i]){
			cout<<1100;
		}
}
	return 0;
}
