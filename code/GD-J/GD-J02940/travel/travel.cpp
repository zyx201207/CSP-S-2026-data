#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	int d=s1[2]-'A';
	int e=s2[2]-'A';
	if(c1==c2){
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<"1";
			if(((d>=0&&d<=2)&&(e>=0&&e<=2))||((d>=3&&d<=4)&&(e>=3&&e<=4))){
				cout<<"1";
				if(abs(d-e)==1){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}
			else{
				cout<<"00";
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
