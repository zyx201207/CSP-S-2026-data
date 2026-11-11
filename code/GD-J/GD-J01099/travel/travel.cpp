#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
cin>>a>>b>>c>>d;
if(a==c){
	cout<<1;
}
else cout<<0;


if(a==c&&b[0]==d[0]&&b[1]==d[1]){
	cout<<1;
}
else cout<<0;


int bj=0;
if(a==c&&b[0]==d[0]&&b[1]==d[1]){
	if(b[2]=='A'){
		if(d[2]=='B'||d[2]=='C'){
			bj=1;
			cout<<1;
		}
	    else cout<<0;
	}
	else if(b[2]=='B'){
		if(d[2]=='A'||d[2]=='C'){
			bj=1;
			cout<<1;
		}
		else cout<<0;
	}
	else if(b[2]=='C'){
		if(d[2]=='A'||d[2]=='B'){
			bj=1;
			cout<<1;
		}
		else cout<<0;
	}
	else if(b[2]=='D'){
		if(d[2]=='F'){
			bj=1;
			cout<<1;
		}
		else cout<<0;
	}
	else if(b[2]=='F'){
		if(d[2]=='D'){
			bj=1;
			cout<<1;
		}
		else cout<<0;
	}
	
}
else cout<<0;


if(bj==1&&abs(int(b[2]-d[2]))==1||bj==1&&b[2]=='D'&&d[2]=='F'||bj==1&&b[2]=='F'&&d[2]=='D'){
	cout<<1;
}
else cout<<0;
return 0;
}

