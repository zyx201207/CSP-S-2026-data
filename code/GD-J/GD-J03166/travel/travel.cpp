#include<bits/stdc++.h>
using namespace std;
long long a,b;
string c,d;
int q,w,e,r;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>c>>b>>d;
	if(a==b){
		q=1;
	}
	else{
		q=0;
		w=0;
		e=0;
		r=0;
		cout<<q<<w<<e<<r<<"\n";
		return 0;
	}
	if(c[0]==d[0]){
		if(c[1]==d[1]){
			w=1;
		}
		else{
			w=0;
			e=0;
			r=0;
			cout<<q<<w<<e<<r<<"\n";
			return 0;
		}
	}
	else{
		w=0;
		e=0;
		r=0;
		cout<<q<<w<<e<<r<<"\n";
		return 0;
	}
	if((c[2]=='A'||c[2]=='B'||c[2]=='C')&&(d[2]=='A'||d[2]=='B'||d[2]=='C')){
		e=1;
	}
	else if((c[2]=='D'||c[2]=='F')&&(d[2]=='D'||d[2]=='F')){
		e=1;
		r=1;
		cout<<q<<w<<e<<r<<"\n";
		return 0;
	}
	else{
		e=0;
		r=0;
		cout<<q<<w<<e<<r<<"\n";
		return 0;
	}
	if((c[2]=='A'&&d[2]=='B')||(c[2]=='B'&&d[2]=='C')||(d[2]=='B'&&c[2]=='C')||(d[2]=='A'&&c[2]=='B')){
		r=1;
		cout<<q<<w<<e<<r<<"\n";
		return 0;
	}
	else{
		r=0;
		cout<<q<<w<<e<<r<<"\n";
		return 0;
	}
	return 0;
}
