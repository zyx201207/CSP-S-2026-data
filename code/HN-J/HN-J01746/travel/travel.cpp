#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2,s;
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			if(s1[2]=='A'){
				if(s2[2]=='B'){
					cout<<11;
				}else if(s[2]=='c'){
					cout<<10;
				}else{
					cout<<"00";
				}
			}else if(s1[2]=='B'){
				if(s2[2]=='A'||s[2]=='C'){
					cout<<11;
				}else{
					cout<<"00";
				}
			}else if(s1[2]=='C'){
				if(s2[2]=='A'){
					cout<<10;
				}else if(s2[2]=='B'){
					cout<<11;
				}else{
					cout<<"00";
				}
			}else if(s1[2]=='D'){
				if(s2[2]=='F'){
					cout<<11;
				}else{
					cout<<"00";
				}
			}else{
				if(s2[2]=='D'){
					cout<<11;
				}else{
					cout<<"00";
				}
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
