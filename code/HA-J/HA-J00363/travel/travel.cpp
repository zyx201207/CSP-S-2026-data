#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int m=0; 
	if(a[1]==c[1]&&a[0]==b[0]){	
		m=1;
		cout<<m;
	if(b[0]==d[0]&&b[1]==d[1]){
		m=1;
		cout<<m;
		if(b[2]=='D'&&d[2]=='F'||b[2]=='F'&&d[2]=='D'){
			m=1;
			cout<<m;
			cout<<m;
	    }else if(b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C'){
			m=1;
			cout<<m;
			if(b[2]=='B'||d[2]=='B'){
				m=1;
				cout<<m;
			}
			else {
				m=0;
				cout<<m;
			}		
		}
		else {
			m=0;
			cout<<m;
			cout<<m;
		}
	}else{
		m=0;
		cout<<m;
		cout<<m;
		cout<<m;
	}
}else{
	cout<<m;
	cout<<m;
	cout<<m;
	cout<<m;
}
	
	
	
	return 0;
}
