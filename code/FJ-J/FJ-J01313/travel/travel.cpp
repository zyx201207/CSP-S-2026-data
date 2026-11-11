#include<bits/stdc++.h>
using namespace std;
char s1[2],s2[2],c1[2],c2[2],c3[2];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=0;i<2;i++) cin>>s1[i]>>s2[i]>>c1[i]>>c2[i]>>c3[i];
	if(s1[0]==s1[1]&&s2[0]==s2[1]){
		cout<<"1";
		if(c1[0]==c1[1]&&c2[0]==c2[1]){
			cout<<"1";
			if(c3[0]<='C'&&c3[1]<='C'&&c3[0]>='A'&&c3[1]>='A'||c3[0]=='C'&&c3[1]=='F'||c3[1]=='C'&&c3[0]=='F'){
				cout<<"1";
				if(c3[0]-c3[1]==1||c3[1]-c3[0]==1){
					cout<<"1";	
				}
				else if(c3[0]=='C'&&c3[1]=='F'||c3[1]=='C'&&c3[0]=='F'){
					cout<<"1";
				}
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}