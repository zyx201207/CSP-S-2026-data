//GZ-J00187  遵义市新蒲中学 王墨霖 
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		string r1,r2;
		for(int i=0;i<2;i++){
			r1+=s1[i];
			r2+=s2[i]; 
		}
		if(r1==r2){
			cout<<"1";
			if((s1[2]>='D'&&s1[2]<='F'&& s2[2]>='D'&&s2[2]<='F') || (s1[2]>='A'&&s1[2]<='C'&& s2[2]>='A'&&s2[2]<='C')){
				cout<<"11";
			}else if((s1[2]>='A'&&s1[2]<='C'&& s2[2]>='A'&&s2[2]<='C')){
				int w=abs(int(s1[2]-s2[2]));
				if(w==1){
					cout<<"11";
				}else{
					cout<<"10";
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

