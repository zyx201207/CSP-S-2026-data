#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b;
	string c,d;
	cin>>a>>c>>b>>d;
	if(a==b)cout<<1;
	else cout<<0;
	if(c[0]==d[0]&&c[1]==d[1]&&a==b) cout<<1;
	else cout<<0;
	if((c[0]==d[0]&&c[1]==d[1]&&a==b)&&((c[2]<='C'&&d[2]<='C')||(c[2]>='D'&&d[2]>='D'))){
		 cout<<1;
	}
	else cout<<0;
	if((c[0]==d[0]&&c[1]==d[1]&&a==b)&&((c[2]<='C'&&d[2]<='C')||(c[2]>='D'&&d[2]>='D'))&&((c[2]==d[2]-1)||(c[2]==d[2]+1))){
			 cout<<1;
			
		}
	else cout<<0;
	
	return 0;
}
