#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		string x1=s1.substr(0,2);
		string x2=s2.substr(0,2);
		if(x1==x2){
			cout<<1;
			int f1=s1[2]-'A',f2=s2[2]-'A';
			bool z1=0,z2=0;
			if(f1==0||f1==1||f1==2){
				z1=1;
			}
			else if(f1==3||f1==4){
				z1=0;
			}
			if(f2==0||f2==1||f2==2){
				z2=1;
			}
			else if(f2==3||f2==4){
				z2=0;
			}
			if(z1==z2){
				cout<<1;
				if(f1+1==f2||f2+1==f1){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else{
				cout<<0;
				cout<<0;
			}
		}
		else{
			cout<<0;
			cout<<0;
			cout<<0;
		}
	}
	else{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
	}
	return 0;
}
