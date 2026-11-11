#include<bits/stdc++.h>
using namespace std;
string s[4];
int a[4][3];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	for(int i=0;i<4;i++) cin>>s[i];
	if(s[1][2]>='A'&&s[1][2]<='C') a[1][2]=1;
	else a[1][2]=2;
	if(s[3][2]>='A'&&s[3][2]<='C') a[3][2]=1;
	else a[3][2]=2;
	if(s[0]==s[2]){
		if(s[1][0]==s[3][0]&&s[1][1]==s[3][1]){
			if((a[1][2]==1&&a[3][2]==1)||(a[1][2]==2&&a[3][2]==2)){
				if(a[1][2]==1){
					if(s[1][2]=='A'&&s[3][2]=='B') cout<<"1111";
					else if(s[1][2]=='B'&&s[3][2]=='A') cout<<"1111";
					else if(s[1][2]=='B'&&s[3][2]=='C') cout<<"1111";
					else if(s[1][2]=='C'&&s[3][2]=='B') cout<<"1111";
					else cout<<"1110";
				}
				else if(a[1][2]==2){
					if(s[1][2]=='D'&&s[3][2]=='F') cout<<"1111";
					else if(s[1][2]=='F'&&s[3][2]=='D') cout<<"1111";
					else cout<<"1110";
				}
			}
			else cout<<"1100";
		}
		else cout<<"1000";
	}
	else cout<<"0000";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
