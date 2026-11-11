#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int n,m,a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	n=(s1[0]-'0')*10+s1[1]-'0';
	m=(s2[0]-'0')*10+s2[1]-'0';
	a=s1[2]-'A'+1;
	b=s2[2]-'A'+1;
	if(c1==c2){
		if(n==m){
			if(1<=a&&a<=3){
				if(1<=b&&b<=3){
					if(abs(a-b)==1){
						cout<<"1111";
						return 0;
					}
					else{
						cout<<"1110";
						return 0;
					}
				}
				else{
					cout<<"1100";
					return 0;
				}
			}
			else{
				if(4<=b&&b<=6){
					cout<<"1111";
					return 0;
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
		return 0;
	}
	return 0;
}
//May all the beauty be blessed.
