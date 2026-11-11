#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
	}
	else{
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<s1.size()-1;i++){
		if(s1[i]==s2[i]){
			cout<<"1";
		}
		else{
			cout<<"000";
			return 0;
		}		
	}
	int a1=s1[2],a2=s2[2];
	if(abs(a1-a2)==1){
		cout<<"1";
	}
	else{
		cout<<"0";
	}
	return 0;
}
