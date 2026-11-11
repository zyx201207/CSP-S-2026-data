#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}else{
		for(int i=0;i<2;i++){
			if(s1[i]!=s2[i]){
				cout<<"1000";
				return 0;
			}
		}
		if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')){
			if((s1[2]=='A'&&s2[2]=='C')||(s1[2]=='C'&&s2[2]=='A')){
				cout<<"1110";
				return 0;
			}else{
				cout<<"1111";
				return 0;
			}
		}else{
			cout<<"1100";
			return 0;
		}
	}
	return 0;
}
