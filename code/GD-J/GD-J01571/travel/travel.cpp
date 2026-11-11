#include<bits/stdc++.h>
using namespace std;

string a,b,c,d;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a[0]==c[0]&&a[1]==c[1]&&'0'<=a[0]&&a[0]<='1'&&'0'<=c[0]&&c[0]<='1'&&'1'<=a[1]&&a[1]<='7'&&'1'<=c[1]&&c[1]<='7'){
		cout<<1;
		if(b[0]==d[0]&&b[1]==d[1]&&'0'<=b[0]&&b[0]<='1'&&'0'<=d[0]&&d[0]<='1'&&'1'<=b[1]&&b[1]<='8'&&'1'<=d[1]&&d[1]<='8'){
			cout<<1;
			if('A'<=b[2]&&b[2]<='C'&&'A'<=d[2]&&d[2]<='C'){
				cout<<1;
				if(b[2]=='B'||d[2]=='B'){
					cout<<1;
				}else cout<<0;
			}else if((b[2]=='D'||b[2]=='F')&&(d[2]=='D'||d[2]=='F')){
				cout<<"11";
			}else{
				cout<<"00";
			}
		}else cout<<"000";
	}else cout<<"0000";
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
