//GZ-J00327 遵义市第十九中学 张锣址杨 
#include <bits/stdc++.h> 
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<"1";
		int a=s1[2]-'A',b=s2[2]-'A'; 
		if((a==3&&b==2)||(a==2&&b==3)){
			cout<<"00";
		}else{
			cout<<"1";
			if(a+1==b||b+1==a){
				cout<<"1";
			}else{
				cout<<"0";
			}
		}
		}else{
			cout<<"000";
		}
	} else{
		cout<<"0000";
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
