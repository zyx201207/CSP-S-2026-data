//GZ-J00253 华东师范大学附属贵阳学校 袁琬潇 
#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,b1,a2,b2;
	cin>>a1>>b1>>a2>>b2;
	int x1=b1[2]-'A',x2=b2[2]-'A';
	if(a1[0]==a2[0]&&a1[1]==a2[1]){
		cout<<"1";
		if(b1[0]==b2[0]){
			if(b1[1]==b2[1]){
				cout<<1;
				if(x1<=2&&x2<=2||x1>=3&&x2>=3) cout<<"1";
				else cout<<"0";
				if(x1-x2==1||x1-x2==-1){
					if(x1==2&&x2==3) cout<<"0";
					else if(x1==3&&x2==2) cout<<"0";
					else cout<<"1";
				}else cout<<"0";
			}else cout<<"000";
		}else cout<<"000";
	}else cout<<"0000"<<endl;
	return 0;
}
