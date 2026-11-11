#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
bool f1=0,f2=0,f3=0,f4=0;
int main(){
	freopen("travel.in",r);
	freopen("travel.out",w);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		f1=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			f2=1;
			int d1,d2;
			if(s1[2]>='A'&&s1[2]<='C') d1=1;
			else d1=2;
			if(s2[2]>='A'&&s2[2]<='C') d2=1;
			else d2=2;
			if(d1==d2){
				f3=1;
				if(d1==2){
					f4=1;
				}
				else{
					if(abs(s1[2]-s2[2])==1){
						f4=1;
					}
				}
			}
		}
	}
	cout<<f1<<f2<<f3<<f4;
	return 0;
}
