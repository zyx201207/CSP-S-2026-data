#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	int num=(a[0]-'0')*10+(a[1]-'0'),sum=(c[0]-'0')*10+(c[1]-'0');
	if(num==sum){
		cout<<1;
		num=(b[0]-'0')*10+(b[1]-'0'),sum=(d[0]-'0')*10+(d[1]-'0');
		if(num==sum){
			cout<<1;
			if(b[2]=='D'||b[2]=='F') num=1;
			else num=0;
			if(d[2]=='D'||d[2]=='F') sum=1;
			else sum=0;
			if(num==sum){
				cout<<1;
				if(num){
					if(b[2]=='D'&&d[2]=='F') cout<<1;
					else if(d[2]=='D'&&b[2]=='F') cout<<1;
					else cout<<0;
				}else{
					if(b[2]=='A'&&d[2]=='B') cout<<1;
					else if(d[2]=='A'&&b[2]=='B') cout<<1;
					else if(b[2]=='C'&&d[2]=='B') cout<<1;
					else if(d[2]=='C'&&b[2]=='B') cout<<1;
					else cout<<0;
				}
			}else cout<<"00";
		}else cout<<"000";
	}else{
		cout<<"0000";
	}
	return 0;
} 
