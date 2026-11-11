#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
	}
	else{
		cout<<1;
		char a1,a2;
		a1=s1[2];
		a2=s2[2];
		int a,b;
		a=(s1[0]-'0')*10+s1[1]-'0';
		b=(s2[0]-'0')*10+s2[1]-'0';
		bool flag=false;
		if(a==b){
			cout<<1;
			if(a1=='A'||a1=='B'||a1=='C'){
				if(a2=='A'||a2=='B'||a2=='C'){
					cout<<1;
					if(a1=='A'){
						if(a2=='B'){
							cout<<1;
							flag=true;
						}
					}
					else if(a1=='B'){
						if(a2=='A'&&a2=='C'){
							cout<<1;
							flag=true;
						}
					}
					else if(a1=='C'){
						if(a2=='B'){
							cout<<1;
							flag=true;
						}
					}
				}
				else
					cout<<0;
			}
			else
				cout<<0;
			if(flag==false){
				if(a1=='D'||a1=='F'){
					if(a2=='D'||a2=='F'){
						cout<<"1";
						if(a1=='D'&&a2=='F'){
							cout<<1;
						}
						else if(a1=='F'&&a2=='D'){
							cout<<1;
						}
						else{
							cout<<0;
						}
					}
					else
						cout<<0;
				}
				else
					cout<<0;
			}
		}
		else{
			cout<<"000";
		}
	}
	return 0;
}
