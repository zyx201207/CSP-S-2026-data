#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3){
		cout<<1;
		if(s2[0]==s4[0]  and s2[1]==s4[1]){
			cout<<1;
			if(s2[2]=='A' or 'B' or 'C'  || s4[2]=='A' or 'B' or 'C'){
				cout<<1;
				int a=s2[2]+'0';
				int b=s4[2]+'0';
				if(a+1 ==b or a-1==b){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else if(s2[2]=='D' or 'F'   || s4[2]=='D' or 'F' ){
				cout<<1;
			}
			else{
				cout<<0<<0;
			}	
		}
		else{
			cout<<0<<0<<0;
		}
	}
	else{
		cout<<0<<0<<0<<0;
	}


	
	return 0;
}
