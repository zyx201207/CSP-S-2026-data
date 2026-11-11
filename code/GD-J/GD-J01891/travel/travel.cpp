#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
    	if(s1[0]==s2[0]&&s1[1]==s2[1]){
				cout<<"1100";
		}
		else{
			cout<<"1000";
		}
	}
	else{
		cout<<"0000";
	}
    return 0;
}
