#include<bits/stdc++.h>
using namespace std;
string a,b,c,d,e,q,p;
char f,g;
int n,m,k;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		e+='1';
		n=b.size();
		m=d.size();
		f=b[n-1];
		g=d[m-1];
		for(int i=0;i<n;i++){
			if(b[i]>=0&&b[i]<='9') q+=b[i];
		}
		for(int i=0;i<m;i++){
			if(d[i]>=0&&d[i]<='9') p+=d[i];
		}
		if(q==p){
			e+='1';
			if((f>='A'&&f<='C'&&g>='A'&&g<='C')||(f>='D'&&f<='F'&&g>='D'&&g<='F')){
				e+='1';
				if((f=='A'&&g=='B')||(f=='B'&&g=='A')||(f=='B'&&g=='C')||(f=='C'&&g=='B')||(f=='D'&&g=='F')||(f=='F'&&g=='D')) e+='1';
				else e+='0';
			}else e+="00";
		}else e+="000";
	}else e+="0000";
	cout<<e<<endl;
}