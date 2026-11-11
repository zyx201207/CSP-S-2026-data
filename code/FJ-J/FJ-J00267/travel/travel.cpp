#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2,a="0",b="0",c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	a=a+s1[1];
	b=b+s2[1];
	c=s1[2];
	d=s2[2];
	if(c1==c2){
		if(a==b){
			if((c=="D"&&d=="F")||(c=="F"&&d=="D")||(c=="A"&&d=="B")||(c=="A"&&d=="C")||(c=="B"&&d=="A")||(c=="C"&&d=="A")||(c=="B"&&d=="C")||(c=="C"&&d=="B")){
				if((c=="D"&&d=="F")||(c=="F"&&d=="D")||(c=="A"&&d=="B")||(c=="B"&&d=="A")||(c=="B"&&d=="C")||(c=="C"&&d=="B")){
					cout<<"1111";
				}
				else{
					cout<<"1110";
				}
			}
			else{
				cout<<"1100";
			}
		}
		else{
			cout<<"1000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}
