#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3){
		cout<<1;
		char c1=s2[0],c2=s2[1],c3=s4[0],c4=s4[1];
		if(c1==c3&&c2==c4){
			cout<<1;
			char c5=s2[2]-'A',c6=s4[2]-'A';
			if((c5<=2&&c6<=2)||(c5>2&&c6>2)){
				cout<<1;
				if((c5>c6&&c5-c6==1)||(c6>=c5&&c6-c5==1)){
					cout<<1;
				}
				else{
					cout<<0;
				}
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
