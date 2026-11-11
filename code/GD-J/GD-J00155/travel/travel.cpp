#include<bits/stdc++.h>
using namespace std;
bool cx(string h,string l){
	if(h[0]==l[0]&&h[1]==l[1]) return true;
	else  return false;
}
bool pai(string x1,string y1){
	if(x1[0]==y1[0]&&x1[1]==y1[1]) return true;
	else if(x1[0]!=y1[0]&&x1[1]==y1[1]) return false;
	else if(x1[0]==y1[0]&&x1[1]!=y1[1]) return false;
	else if(x1[0]!=y1[0]&&x1[1]!=y1[1]) return false;
}
bool s(string a,string b,string x,string y){
	char c=b[b.size()-1];
	char h=y[y.size()-1];
	if((cx(a,x)==true)&&(pai(b,y)==true)) {
		if((c>='D'&&h>='D')||(c<'D'&&h<'D')) return true;
		else return false;
	}
}
bool p(string a,string b,string x,string y){
	char c=b[b.size()-1];
	char h=y[y.size()-1];
	int t=abs(c-h); 
	
		if((c>='D'&&h>='D')) return true;
		if(t==1&&c<'D'&&h<'D'){
			return true;
		}
        else return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,x,y;
	cin>>a>>b>>x>>y;
	if(cx(a,x)==true) cout<<1;
	if(cx(a,x)==false) cout<<0;
	if(cx(a,x)==true&&pai(b,y)==true) cout<<1;
	if(cx(a,x)==false||pai(b,y)==false) cout<<0;
	if(cx(a,x)==true&&pai(b,y)==true&&s(a,b,x,y)==true) cout<<1;
	if(cx(a,x)==false||pai(b,y)==false||s(a,b,x,y)==false) cout<<0;
	if(cx(a,x)==true&&pai(b,y)==true&&s(a,b,x,y)==true&&p(a,b,x,y)==true) cout<<1;
	if(cx(a,x)==false||pai(b,y)==false||s(a,b,x,y)==false||p(a,b,x,y)==false) cout<<0;
	return 0;
}
