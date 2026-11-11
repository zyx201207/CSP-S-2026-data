#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	bool f1=0,f2=0,f3=0,f4=0;
	if(c1!=c2){
		f1=0;
		f2=0;
		f3=0;
		f4=0;
	}else{
		f1=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			f2=1;
			if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C'||(s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')){
				f3=1;
				if(s1[2]=='A'&&s2[2]=='B'||s1[2]=='B'&&s2[2]=='A'||s1[2]=='B'&&s2[2]=='C'||s1[2]=='C'&&s2[2]=='B'||s1[2]=='D'&&s2[2]=='F'||s1[2]=='F'&&s2[2]=='D'){
					f4=1;
				}
			}
		}
	}
	cout<<f1<<f2<<f3<<f4;
	return 0;
}
