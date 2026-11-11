#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
bool f[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		f[1]=true;
		if(b.substr(0,2)==d.substr(0,2)){
			f[2]=true;
			if((b[2]>='D'&&d[2]>='D')||(b[2]<='C'&&d[2]<='C')){
				f[3]=true;
				if(abs(b[2]-d[2])==1) f[4]=true;
			}
		}
	}
	for(int i=1;i<=4;i++) cout<<f[i];
	return 0;
} 
