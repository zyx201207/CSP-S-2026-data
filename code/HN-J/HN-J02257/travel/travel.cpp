#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	long long e,f,g,h;
	string a,b,c,d;
	g=0;
	h=0;
	cin>>a>>b>>c>>d;
	if(a==c){
		e=1;
	}else{
		e=0;
	}
	if(b[1]==d[1] && b[0]==d[0]){
		f=1;
	}else{
		f=0;
	}
	if(b[2]>=68 && d[2]<68){
		g=0;
	}
	if(d[2]>=68 && b[2]<68){
		g=0;
	}
	if(d[2]<68 && b[2]<68){
		g=1;
	}
	if(d[2]>=68 && b[2]>=68){
		g=1;
		h=1;
	}
	if(d[2]-b[2]>=2 || b[2]-d[2]>=2){
		h=0;
	}else{
		h=1;
	}
	cout<<e<<f<<g<<h<<endl;
	return 0;
}
