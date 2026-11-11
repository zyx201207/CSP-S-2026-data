#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("trave.in","r",stdin);
	freopen("trave.out","w",stdout);
	string a,b,c,d,s;
	cin>>a>>b>>c>>d;
	if(a[0]==c[0]&&a[1]==c[1]){
		s=s+'1';
	}
	else{
		s=s+'0';
	}
	if(b[0]==d[0]&&b[1]==d[1]&&a[0]==c[0]&&a[1]==c[1]){
		s=s+'1';
	}
	else{
		s=s+'0';
	}
	if(b[2]>='D'&&d[2]>='D'&&b[0]==d[0]&&b[1]==d[1]&&a[0]==c[0]&&a[1]==c[1]){
		s=s+'1';
		s=s+'1';
	}
	else if(b[2]<='C'&&d[2]<='C'&&b[0]==d[0]&&b[1]==d[1]&&a[0]==c[0]&&a[1]==c[1]){
		s=s+'1';
		if(b[2]-1==d[2]||b[2]+1==d[2]){
			s=s+'1';
		}
		else{
			s=s+'0';
		}
	}
	else{
		s=s+'0';
		s=s+'0';
	}
	cout<<s;
return 0;
}
