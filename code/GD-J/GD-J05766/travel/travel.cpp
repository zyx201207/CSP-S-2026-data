#include<bits/stdc++.h>
using namespace std;
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	char a1=c1[1];
	char b1=c2[1];
	int a2=s1[0]+s1[1];
	int a3=s2[0]+s2[1];
	if(a1==b1){
		cout<<1;
		if(a2==a3){
			cout<<1;
			if((s1[2]<='C'&&s2[2]<='C')||(s1[2]!='C'&&s2[2]!='C'&&s1[2]>='D'&&s2[2]>='D')){
				cout<<1;
				if((s1[2]==s2[2]+1)||(s1[2]==s2[2]-1)){
					cout<<1;
				}
				else{
					cout<<"0";
					return 0;
				}
			}
			else{
				cout<<"00";
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
	return 0;
}
