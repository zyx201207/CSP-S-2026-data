#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
struct node{
	string id;
	char hang;
	int lie;
};
node R,X;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	R.id=c1; X.id=c2;
	R.lie=10*(s1[0]-'0')+(s1[1]-'0');
	X.lie=10*(s2[0]-'0')+(s2[1]-'0');
	R.hang=s1[2]; X.hang=s2[2];
	if(R.id==X.id){
		cout<<1;
		if(R.lie==X.lie){
			cout<<1;
			int rh=R.hang,xh=X.hang;
			if(('A'<=rh&&rh<='C'&&'A'<=xh&&xh<='C')||('D'<=rh&&rh<='F'&&'D'<=xh&&xh<='F')){
				cout<<1;
				if(abs(rh-xh)==1){
					cout<<1;
					return 0;
				}else{
					cout<<"0";
					return 0;
				}
			}else{
				cout<<"00";
				return 0;
			}
		}else{
			cout<<"000";
			return 0;
		}
	}else{
		cout<<"0000";
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
