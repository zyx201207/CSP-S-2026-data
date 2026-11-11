//GZ-J00650兴义市弘毅中学 秦智铭 
#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main (){	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
			if(s1[1]==s2[1]&&s2[2]==s2[2]){
				cout<<1100;
			}else{
				cout<<1000;
			}
		}else{
		cout<<"0000";
	}
	return 0;
}
