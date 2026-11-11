#include<bits/stdc++.h>
using namespace std;
string r1,r2,s1,s2;
int n1,n2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r1>>s1>>r2>>s2;
	if(r1==r2){
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<"1";
			n1=s1[2]-64;
			n2=s2[2]-64;
			if((n1<4&&n2<4)||(n1>3&&n2>3)){
				cout<<"1";
				if(abs(n1-n2)<2){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}
