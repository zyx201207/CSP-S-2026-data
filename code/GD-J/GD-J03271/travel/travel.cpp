#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string c1,s1,c2,s2,a="",b1,b2;
	cin>>c1>>s1>>c2>>s2;
	b1=s1[0]+s1[1];
	b2=s2[0]+s2[1];
	if(c1==c2){
		a+="1";
		if(b1==b2){
			a+="1";
			char d1=s1[2];
			char d2=s2[2];
			if('A'<=d1&&d1<='C'&&'A'<=d2&&d2<='C'){
				a+="1";
				if(d1!='B'&&d2!='B'){
					a+="0";
				}
				else{
					a+="1";
				}
			}
			else if('D'<=d1&&d1<='F'&&'D'<=d2&&d2<='F'){
				a+="11";
			}
			else{
				a+="00";
			}
		}
		else{
			a+="000";
		}
	}
	else{
		a+="0000";
	}
	cout<<a;
	return 0;
} 
