#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	if(c1 == c2){
		cout << "1";
	}
	else{
		cout << "0000";
		return 0;
	}
	for(int i=0;i<=1;i++){
		if(s1[1]==s2[1]){
			cout<<"1";
			break;

		}
		else{
			cout<<"0";
			break;
		}
	}
	for(int i=0;i<=2;i++){
		if(s1[1]==s2[1]){
			if(s1[2]==65&&s2[2]==66||s1[2]==65&&s2[2]==67||s1[2]==66&&s2[2]==65||s1[2]==66&&s2[2]==67||s1[2]==67&&s2[2]==65||s1[2]==67&&s2[2]==66||s1[2]==68&&s2[2]==69||s1[2]==69&&s2[2]==68){
			cout<<"1";
			break;
		}
		else{
			cout<<"0";
			break;
		}
		}
	}
    if(s1[2]==65&&s2[2]==66||s1[2]==66&&s2[2]==65||s1[2]==66&&s2[2]==67||s1[2]==67&&s2[2]==66||s1[2]==68&&s2[2]==69||s1[2]==69&&s2[2]==68){
        cout<<"1";
    }
    else{
        cout<<"0";
    }
	return 0;
}
