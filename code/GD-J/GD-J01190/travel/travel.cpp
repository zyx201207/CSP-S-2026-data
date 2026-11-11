#include <bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a[0]==c[0]&&a[1]==c[1]){
		cout<<1;
	}else{
		cout<<0;
	}
	if(b[1]==d[1]&&b[0]==d[0]&&a[0]==c[0]&&a[1]==c[1]){
		cout<<1;
	}else{
		cout<<0;
	}
	if(b[1]==d[1]&&b[0]==d[0]&&((b[2]-'A'<3&&d[2]-'A'<3)||(b[2]-'A'>3&&d[2]-'A'>3))&&a[0]==c[0]&&a[1]==c[1]){
		cout<<1;
	}else{
		cout<<0;
	}
	int n=b[2]-'A',m=d[2]-'A';
	if(b[1]==d[1]&&b[0]==d[0]&&((b[2]-'A'<3&&d[2]-'A'<3)||(b[2]-'A'>3&&d[2]-'A'>3))&&abs(n-m)==1&&a[0]==c[0]&&a[1]==c[1]){
		cout<<1;
	}else{
		cout<<0; 
	}
	return 0;
}
