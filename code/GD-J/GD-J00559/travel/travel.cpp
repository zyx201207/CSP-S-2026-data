#include<bits/stdc++.h>
using namespace std;
string ans;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
//	cout<<c1<<" "<<s1<<" "<<c2<<" "<<s2;
	if(c1==c2){
		ans+="1";
		string t1=s1.substr(0,2);
		string t2=s2.substr(0,2);
		if(t1==t2){
			ans+="1";
			char q1=s1[2],q2=s2[2];	
			if(q1=='A'||q1=='B'||q1=='C'){
				if(q2=='A'||q2=='B'||q2=='C'){
					ans+="1";
					if(q1=='A'){
						if(q2=='B'){
							cout<<"1111";
							return 0;
						}
						else{
							cout<<"1110";
							return 0;
						}
					}
					else if(q1=='B'){
							if(q2=='A'||q2=='C'){
							cout<<"1111";
							return 0;
						}
						else{
							cout<<"1110";
							return 0;
						}
					}
					else{
						if(q2=='B'){
							cout<<"1111";
							return 0;
						}
						else{
							cout<<"1110";
							return 0;
						}
					}
				}
				else{
					cout<<"1100";
					return 0;
				}
			}
			else{
				if(q2=='D'||q2=='F'){
					ans+="1";
					if(q1=='D'){
						if(q2=='F'){
							cout<<"1111";
							return 0; 
						}
						else{
							cout<<"1110";
							return 0;
						}
					}
					else{
						if(q2=='D'){
							cout<<"1111";
							return 0;
						}
						else{
							cout<<"1110";
							return 0;
						}
					} 
				}
				else{
					cout<<"1100";
					return 0;
				}
			}
		}
		else{
			cout<<"1000";
			return 0;
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}
