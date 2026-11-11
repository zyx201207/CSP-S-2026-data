#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	}
	else if(c1!=c2){
		cout<<"0000"; 
	} 
	string a[5]=s1,b[5]=s2;
	for(int i=0;i<3;i++){
		a[i]=s1[i];
		b[i]=s2[i];
	}
		if(c1==c2){
		if(a[0]==b[0]){
			if(a[1]==b[1]){
				cout<<"1";
				if(a[2]=="D"){
			if(b[2]=="F")
			cout<<"11";
			else{
				cout<<"00";
			}
		}
		if(a[2]=="F"){
			if(b[2]=="D")
			cout<<"11";
			else{
				cout<<"00";
			}
		}
		if(a[2]=="A"){
			if(b[2]=="B")
			cout<<"11";
			else if(b[2]=="C")
			cout<<"10";
			else{
				cout<<"00";
			}
		}
		if(a[2]=="B"){
			if(b[2]=="A"||b[2]=="C")
			cout<<"11";
			else{
				cout<<"00";
			}
		}
		if(a[2]=="C"){
			if(b[2]=="B")
			cout<<"11";
			else if(b[2]=="A")
			cout<<"10";
			else{
				cout<<"00";
		}
	}
				}
				else{
					cout<<"000";
				}
			}
			else if(a[0]!=b[0]||a[1]!=b[1]){
				cout<<"000";
				}
		
}
	return 0;
} 
