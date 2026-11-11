#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2;
	int c1,c2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<'1';
		int p1=(s1[0]-'0')*10+(s1[1]-'0');
		int p2=(s2[0]-'0')*10+(s2[1]-'0');
		if(p1==p2){
			cout<<'1';
			bool side1=0,side2=0;
			if(s1[2]-'A'>=3)side1=1;
			if(s2[2]-'A'>=3)side2=1;
			if(side1==side2){
				cout<<'1';
				if(abs((s1[2]-'A')-(s2[2]-'A'))==1){
					cout<<'1';
				}else cout<<"0";
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	fclose(stdin);
	fclose(stdout);
}
