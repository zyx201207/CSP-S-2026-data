#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			if(((s1[2]<='C'&&s1[2]>='A')&&(s2[2]>='A'&&s2[2]<='C'))||((s1[2]<='F'&&s1[2]>='E')&&(s2[2]>='E'&&s2[2]<='F'))){
				if((s1[2]-s2[2]==1)||(s2[2]-s1[2]==1)){
					cout<<"1 1 1 1"<<endl; 
				}
				else{
					cout<<"1 1 1 0"<<endl;
				}
			}
			else{
				cout<<"1 1 0 0"<<endl;
			}
		}
		else{
			cout<<"1 0 0 0"<<endl;
	    }
	}
	else{
		cout<<"0 0 0 0"<<endl;
	}
	return 0;
} 
