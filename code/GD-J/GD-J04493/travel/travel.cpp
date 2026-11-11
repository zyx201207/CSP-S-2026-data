#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2,a,b;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1 == c2){
		cout<<"1";
		for(int i=0;i<2;i++){
			if(s1[i] == s2[i]){
				cout<<"1";
			}
		}
	}else{
		cout<<"0000";
		return 0;
	}
	if('s1[2]'+1== 's2[2]' || 's2[2]'+1== 's1[2]'){
		cout<<"1";
	}else{
		cout<<"0";
	}
	return 0;
}
