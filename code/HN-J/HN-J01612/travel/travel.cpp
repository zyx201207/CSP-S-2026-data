#include<iostream>
#include<string>
using namespace std;
string c1,s1,c2,s2;
string pai1,pai2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	pai1=s1[0]+s1[1];
	pai2=s2[0]+s2[1];
	if(c1==c2){
		cout<<1;
		if(pai1==pai2){
			cout<<1;
			if(s1[2]=='D'||s1[2]=='F'){
				if(s2[2]=='D'||s2[2]=='F'){
					cout<<1<<1;
				}else{
					cout<<0<<0;
				}	
			}else{
				if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
					cout<<1;
					if(s1[2]=='A'){
						if(s2[2]=='B'){
							cout<<1;
						}else{
							cout<<0;
						}
					}else if(s1[2]=='B'){
							cout<<1;
					}else{
						if(s2[2]=='B'){
							cout<<1;
						}else{
							cout<<0;
						}
					}
				}else{
					cout<<0<<0;
				}
			}
		}else{
			cout<<0<<0<<0;
		}
	}else{
		cout<<0<<0<<0<<0;
	}
	return 0;
}
