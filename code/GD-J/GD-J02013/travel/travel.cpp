#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int a[256];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	a['A']=1;
	a['B']=2;
	a['C']=3;
	a['D']=4;
	a['F']=5;
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<"1";
			if(a[s1[2]]>=1&&a[s1[2]]<=3&&a[s2[2]]>=1&&a[s2[2]]<=3||a[s1[2]]>=4&&a[s1[2]]<=5&&a[s2[2]]>=4&&a[s2[2]]<=5){
				cout<<"1";
				if(abs(a[s1[2]]-a[s2[2]])==1){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	
	
	return 0;
}
