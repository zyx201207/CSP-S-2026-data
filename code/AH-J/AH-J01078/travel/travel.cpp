#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)cout<<"0000"<<endl;
	else{
		cout<<"1";
		if(s1[0]!=s2[0]||s1[1]!=s2[1])
			cout<<"000"<<endl;
		else{
			cout<<"1";
			if((s1[2]-'A')/3!=(s2[2]-'A')/3)
				cout<<"00"<<endl;
			else{
				cout<<"1";
				if(abs(s1[2]-s2[2])!=1)
					cout<<"0"<<endl;
				else cout<<"1"<<endl;
			}
		}
	}
	return 0;
}
