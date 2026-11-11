#include <bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4,s5,s6;
char x,y;
bool guo(char c,char d){
	if((c>='A'&&c<='C')&&(d>='A'&&d<='C')){
		return true;
	}
	else if((c>='D'&&c<='F')&&(d>='D'&&d<='F')){
		return true;
	}
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >>s1 >>s2 >>s3 >>s4;
	if(s1==s3){
		cout <<1;
			int n=s2.size();
		for(int i=0;i<n-1;i++){
			char c=s2[i],d=s4[i];
			s5+=c;
			s6+=d;
		}
		if(s5==s6){
			cout <<1;
			 x=s2[2],y=s4[2];
			if(guo(x,y)==true){
				cout <<1;
				int m=abs(x-y);
					if(m==1){
						cout <<1;
				}
				else{
					cout <<"0";
				}
			}
			else{
				
				cout <<"00";
			}
		}
		else{
			cout <<"000";
		}
	}
	else{
		cout <<"0000";
	}



	return 0;
}

