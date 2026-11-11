#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>s1>>s2>>s3>>s4;
    int c1=(s1[0]-'0')*10+s1[1]-'0';
    int c2=(s3[0]-'0')*10+s3[1]-'0';
    int z1=(s2[0]-'0')*10+s2[1]-'0';
    int z2=(s4[0]-'0')*10+s4[1]-'0';
    int n1=s2[2];
    int n2=s4[2];
    if(c1==c2){
    	cout<<"1";
    	if(z1==z2){
    		cout<<"1";
    		if(n1>=65&&n1<=67&&n2>=65&&n2<=67||n1>=68&&n1<=69&&n2>=68&&n2<=69){
    			cout<<"1";
    			if(abs(n1-n2)==1){
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
