#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		string ss1=s1.substr(0,2),ss2=s2.substr(0,2);
		char z1[3]={'A','B','C'},z2[2]={'D','F'};
		if(ss1==ss2){
			cout<<"1";
			int f1=0,f2=0;
			char s12=s1[2],s22=s2[2];
			for(int i=0;i<3;i++){
				if(z1[i]==s12){
					f1=1;
				}
				if(z1[i]==s22){
					f2=1;
				}
			}
			for(int i=0;i<2;i++){
				if(z2[i]==s12){
					f1=2;
				}
				if(z2[i]==s22){
					f2=2;
				}
			}
			if(f1==f2){
				cout<<"1";
				if(s12>s22){
					swap(s12,s22);
				}
				if((s12=='A'&&s22=='B')||(s12=='B'&&s22=='C')||(s12=='D'&&s22=='F')){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
