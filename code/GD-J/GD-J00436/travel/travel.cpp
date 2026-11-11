#include <iostream>
#include <string> 
using namespace std;
void js(){
	ios::sync_with_stdio(0);
	cin.tie(0); 
}
string a,x,b,y;
bool fa,fb,fc,fd; 
int worka(){
	if(a==b) return fa=1;
	return 0;
}
int workb(){
	if(fa){
		string q="",p="";
		q=q+x[0]+x[1];
		p=p+y[0]+y[1];
		if(q==p) return fb=1;
	}
	return 0;
}
int workc(){
	if(fb){
		string c="",cc="";
		c+=x[2];
		cc+=y[2];
		if(((c=="A"||c=="B"||c=="C")&&(cc=="A"||cc=="B"||cc=="C"))||((c=="D"||c=="F")&&(cc=="D"||cc=="F"))) return fc=1;
	}
	return 0;
}
int workd(){
	if(fc){
		string c="",cc="";
		c+=x[2];
		cc+=y[2];
		if((c=="D"||c=="F")&&(cc=="D"||cc=="F")) return 1;
		else if(((c=="A"||c=="B")&&(cc=="A"||cc=="B"))||((c=="B"||c=="C")&&(cc=="B"||cc=="C"))) return 1;
	}
	return 0;
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	js();
	cin>>a>>x>>b>>y;
	cout<<worka();
	cout<<workb();
	cout<<workc();
	cout<<workd();
	return 0;
} 
