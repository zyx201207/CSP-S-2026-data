#include<iostream>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int s=int(b[0]-'0')*10+int(b[1]-'0');
	int t=int(d[0]-'0')*10+int(d[1]-'0');
	if(a==c){
		cout<<1;
		if(s==t){
			cout<<1;
			if(b[2]=='A'){
				if(d[2]=='B')cout<<11;
				else if(d[2]=='C')cout<<10;
				else cout<<"00";
			}
			if(b[2]=='B'){
				if(d[2]=='A'||d[2]=='C')cout<<11;
				else cout<<"00";
			}
			if(b[2]=='C'){
				if(d[2]=='B')cout<<11;
				else if(d[2]=='A')cout<<10;
				else cout<<"00";
			}
			if(b[2]=='D'){
				if(d[2]=='F')cout<<11;
				else cout<<"00";
			}
			if(b[2]=='F'){
				if(d[2]=='D')cout<<11;
				else cout<<"00";
			}
		}
		else cout<<"000";
	}
	else cout<<"0000";
	
	return 0;
} 
