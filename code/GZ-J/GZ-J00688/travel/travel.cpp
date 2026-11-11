//GZ-J00688 遵义市第十二中学 刘俊逸 
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1[0]+s1[1]==s2[0]+s2[1]){
			cout<<1;
			if(s1[2]+s2[2]==131 or s1[2]+s2[2]==133 or s1[2]+s2[2]==138){
				cout<<"11";
			}
			else if(s1[2]+s2[2]==132){
				cout<<"10";
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}
