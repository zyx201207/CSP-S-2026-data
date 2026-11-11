//GZ-J00228 ¸¶ÐÂ¾þÓð 
#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int flag1=0,flag2=0;
char seatlef[3]={'A','B','C'};
char seatrig[2]={'D','F'};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0] && c1[1]==c2[1]){
		cout<<1;
		if(s1[0]==s2[0] && s1[1]==s2[1]){
			cout<<1;
			for(int i = 0;i<3;i++){
				if(s1[2]==seatlef[i]){
					flag1=1;
				}
				if(s2[2]==seatlef[i]){
					flag2=1;
				}
			}
			if(flag1 && flag2){
				cout<<1;
				if((s2[2]=='C' && s1[2]=='A') || (s1[2]=='C' && s2[2]=='A')){
					cout<<0;
					return 0;
				}else{
					cout<<1;
					return 0;
				}
			}else if(!flag1 && !flag2){
				cout<<11;
				return 0;
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
	return 0;
}
