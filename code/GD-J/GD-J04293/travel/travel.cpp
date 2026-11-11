#include<bits/stdc++.h>
using namespace std;
int c1,c2;
char s1[4],s2[4];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1[1]>>s1[2]>>s1[3]>>c2>>s2[1]>>s2[2]>>s2[3];
	if(c1==c2) {
		cout<<"1";
		if(s1[1]==s2[1] && s1[2]==s2[2]){
			cout<<"1";
			if((s1[3]<'D'&&s2[3]<'D')||(s1[3]>='D'&&s2[3]>='D')){
				cout<<"1";
				if(s2[3]-1==s1[3]||s2[3]+1==s1[3]){
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
