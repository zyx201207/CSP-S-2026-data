#include<bits/stdc++.h>
using namespace std;
long long c1,c2,a1,a2;
char A,B;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	a1=(s1[0]-'0')*10+(s1[1]-'0');
	A=s1[2];
	a2=(s2[0]-'0')*10+(s2[1]-'0');
	B=s2[2];
//	cout<<c1<<' '<<a1<<' '<<A<<' '<<c2<<' '<<a2<<' '<<B;
	if(c1==c2){//#1
		cout<<'1';
		if(a1==a2){//#2
			cout<<'1';
			//#3
			bool z1,z2;
			if(A=='A'||A=='B'||A=='C') z1=1;
			else z1=0;
			if(B=='A'||B=='B'||B=='C') z2=1;
			else z2=0;
//			cout<<'\n'<<z1<<' '<<z2<<'\n';
			if(z1==z2){//#4
				cout<<'1';
				if(z1==0&&z2==0){
					cout<<'1';
					return 0;
				}
				else if(A=='A'&&B=='B'||A=='B'&&B=='A'||A=='B'&&B=='C'||A=='C'&&B=='B'){
					cout<<'1';
					return 0;
				}
				else{
					cout<<'0';
					return 0;
				}
			}
			else{
				cout<<"00";
				return 0;
			}
		}
		else{
			cout<<"000";
			return 0;
		}
	}
	else{
		cout<<"0000";
		return 0;
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}
