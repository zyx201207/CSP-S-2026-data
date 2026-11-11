#include<bits/stdc++.h>
using namespace std;
char s1[3],s2[3];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,c1,c2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			a=abs(int(s1[2])-int(s2[2]));
			if(a<=2){
				if(a==1||(a==2&&(s1[2]=='F'||s2[2]=='F'))) cout<<"1111";
				else cout<<"1110";
			}else cout<<"1100";
		}else cout<<"1000";
	}
	else cout<<"0000";
	return 0;
}
