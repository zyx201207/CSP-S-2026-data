#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int s=0;
int main(){
    freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a[0]==c[0]&&a[1]==c[1]) cout<<1;
	else cout<<0;
	if(a[0]==c[0]&&a[1]==c[1]&&b[0]==d[0]&&b[1]==d[1]) cout<<1;
	else cout<<0;
	if(a[0]==c[0]&&a[1]==c[1]&&b[0]==d[0]&&b[1]==d[1]){
		if(b[2]<='C'&&d[2]<='C'){
			cout<<1;
		}else{
			if(b[2]>='D'&&d[2]>='D'){
				cout<<1;
			}else {
			cout<<0;
		s=1;}
		}
	}else{
	cout<<0;
	s=1;
	 }
	if(s==0){
		if(b[2]-d[2]==1||d[2]-b[2]==1){
			cout<<1;
		}else
			 cout<<0;
		}else cout<<0;
return 0;}

