#include<bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2,a,b;
int f1,f2;

int main(){
	freopen("travel5.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	
	for(int i=0;i<=1;i++){
		a+=s1[i];
		b+=s2[i];
	}
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){	//	ÄÄÒ»²à 
		f1=1;
	}else{
		f1=2;
	}
	if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
		f2=1;
	}else{
		f2=2;
	}
	
	if(c1==c2){
		if(a==b){
			if(f1==f2){
				if((s1[2]=='C'&&s2[2]=='D')||(s2[2]=='C'&&s1[2]=='D')){
					cout<<"1110";
				}else if(abs(int(s1[2]-s2[2]))==1){
					cout<<"1111";
				}else{
					cout<<"1110";
				}
			}else{
				cout<<"1100";
			}
		}else{
			cout<<"1000";
		}
	}else{
		cout<<"0000";
	} 
	return 0;
}
