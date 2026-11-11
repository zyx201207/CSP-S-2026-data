#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,c1,c2;
	cin>>s1>>s2>>c1>>c2;
	int f1=0,f2=0,f3=0,f4=0;
	int f=0;
	if(s1[0]==c1[0]&&s1[1]==c1[1]){
		f1=1;
		if(s2[0]==c2[0]&&s2[1]==c2[1]){
			f2=1;
			if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
				f=1;
			}else{
				f=2;
			}
			if(c2[2]=='A'||c2[2]=='B'||c2[2]=='C'){
				if(f==1){
					f3=1;
				}
			}else{
				if(f==2){
					f3=1;
				}
			}
		}
		if(f3==1){
			if(s2[2]=='C'){
				if(c2[2]=='B'){
					f4=1;
				}
			}
			if(s2[2]=='D'){
				if(c2[2]=='F'){
					f4=1;
				}
			}
			if(s2[2]=='A'){
				if(c2[2]=='B'){
					f4=1;
				}
			}
			if(s2[2]=='B'){
				if(c2[2]=='A'||c2[2]=='B'){
					f4=1;
				}
			}
			if(s2[2]=='F'){
				if(c2[2]=='D'){
					f4=1;
				}
			}
		}
		
	}
	cout<<f1<<f2<<f3<<f4;
	return 0;
} 
