#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	long long a,b,z1,z2;
	bool q1=0,q2=0,q3=0,q4=0;
	for(int i=0;i<c1.size();i++){
		a=c1[i]-'0';
		b=c2[i]-'0';
	}
	long long p1,p2;
	for(int i=0;i<s1.size()-1;i++){
		p1=s1[i]-'0';
		p2=s2[i]-'0';
	}
	z1=s1[2]-'0';
	z2=s2[2]-'0';                                                                
	if(a==b){
		cout<<'1';
		if(p1==p2){
		    cout<<'1';
			if(z1<20&&z2<20){
				cout<<'1';
				if(s1[2]-'0'==s2[2]-'0'-1||s2[2]-'0'==s1[2]-'0'-1||s1[2]-'0'==s2[2]-'0'-2||s2[2]-'0'==s1[2]-'0'-2){
					cout<<'1';
					return 0;
				}
				else{
					cout<<"0";
					return 0;
				}
			}else{
				if(z1>19&&z2>19){
					cout<<"1";
				}else{
					cout<<"00";
		        	return 0;
				}
				
			}
		}else{
			cout<<"000";
			return 0;
		}
	}else{
		cout<<"0000";
		return 0;
	}
	return 0;
}
