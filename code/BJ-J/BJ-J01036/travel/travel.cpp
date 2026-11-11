#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	bool f1=0,f2=0,f3=0,f4=0;
	cin>>c1>>s1>>c2>>s2;
	int p1=(s1[0]-'0')*10+(s1[1]-'0');
	int p2=(s2[0]-'0')*10+(s2[1]-'0');
	char h1=s1[2];
	char h2=s2[2];	
	if(c1==c2){
		f1=1;
		if(p1==p2){
			f2=1;
			if((h1<='C'&&h2<='C')||(h1>='D'&&h2>='D')){
				f3=1;
				if(abs(h1-h2)==1)f4=1;
			}
		}
	}
	cout<<f1<<f2<<f3<<f4;
	return 0;
}
