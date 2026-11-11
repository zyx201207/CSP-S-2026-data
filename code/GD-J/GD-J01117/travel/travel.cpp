#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>c2>>s1>>s2;
	if(c1!=s1){
		cout<<"0000";
		return 0;
	}
	else{
		if(c2[0]==s2[0]&&c2[1]==s2[1]){
			if((c2[2]>='A'&&c2[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||(c2[2]>='D'&&c2[2]<='F'&&s2[2]>='D'&&s2[2]<='F')){
				if(abs(c2[2]-s2[2])==1){
					cout<<"1111";
					return 0;
				}
				else{
					cout<<"1110";
					return 0;
				}
			}
			else{
				cout<<"1100";
				return 0;
			}
		}
		else{
			cout<<"1000";
			return 0;
		}
	}
	return 0;
}
