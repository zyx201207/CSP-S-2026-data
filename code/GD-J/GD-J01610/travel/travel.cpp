#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	int e=0,f=0,g=0,h=0;
	cin>>a>>b>>c>>d;
	for(int i=0;i<2;i++){
		if(a[i]==c[i])e++;
	}
	if(e==2){
		cout<<1;
		e=1;
	}
	else{
		cout<<0;
		e=0;
	}
	for(int i=0;i<2;i++){
		if(b[i]==d[i])f++;
	}
	if(f==2&&e==1){
		cout<<1;
		f=1;
	}
	else{
		cout<<0;
		f=0;
	}
	if(((b[2]=='A'&&(d[2]=='B'||d[2]=='C'))||(b[2]=='B'&&(d[2]=='A'||d[2]=='C'))||(b[2]=='C'&&(d[2]=='B'||d[2]=='A'))||(b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D'))&&f==1&&e==1){
		cout<<1;
		g=1;
	}
	else{
		cout<<0;
		g=0;
	}
	if(((b[2]=='A'&&d[2]=='B')||(b[2]=='B'&&(d[2]=='A'||d[2]=='C'))||(b[2]=='C'&&d[2]=='B')||(b[2]=='D'&&d[2]=='F')||(b[2]=='F'&&d[2]=='D'))&&f==1&&e==1&&g==1){
		cout<<1;
		h=1;
	}
	else{
		cout<<0;
		h=0;
	}
	return 0;
}
