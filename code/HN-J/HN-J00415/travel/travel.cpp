#include<bits/stdc++.h>
using namespace std;
string s="0000";
char s1[4],s2[4],c1[3],c2[3];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1[1]>>c1[2];
	cin>>s1[1]>>s1[2]>>s1[3];
	cin>>c2[1]>>c2[2];
	cin>>s2[1]>>s2[2]>>s2[3];
	if(c1[1]!=c2[1] || c1[2]!=c2[2]){
		cout<<"0000";
		return 0;
	}else if(c1[1]==c2[1] && c1[2]==c2[2]){
		if(s1[1]!=s2[1] || s1[2]!=s2[2]){
			cout<<"1000";
			return 0;
		}else{
			if(((int)s1[3]<=67 && (int)s2[3]>=68) || (s1[3]>=68 && s2[3]<=67)){
				cout<<"1100";
				return 0;
			}else{
				if((int)s1[3]!=(int)s2[3]-1 && (int)s1[3]!=(int)s2[3]+1){
					cout<<"1110";
					return 0;
				}
			}
		}
	}
	cout<<"1111";
	return 0;
}
