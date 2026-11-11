#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,s1,s2;
	char s1_,s2_;
	cin>>c1>>s1>>s1_>>c2>>s2>>s2_;
	//是否在同一节车厢
	if(c1==c2) {
		cout<<"1";
		//是否在同一排
		if(s1==s2) {
			cout<<"1";
			//是否在过道的同一侧
			if(((s1_=='A'||s1_=='B'||s1_=='C')&&(s2_=='A'||s2_=='B'||s2_=='C'))||((s1_=='D'||s1_=='F')&&(s2_=='D'||s2=='F'))){
				cout<<"1";
				//是否相邻
				if((s1_=='A'&&s2_=='B')||(s1_=='B'&&s2_=='A')||(s1_=='B'&&s2_=='C')||(s1_=='C'&&s2_=='B')||(s1_=='D'&&s2_=='F')||(s1_=='F'&&s2_=='D')){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
			}
		} else {
			cout<<"000";
		}
	} else {
		cout<<"0000";
	}
	return 0;
}

