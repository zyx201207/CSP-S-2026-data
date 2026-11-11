#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool check(string x){
	if(x[2]=='D'||x[2]=='F')return 1;
	else return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
	}else{
		if(!(s1[0]==s2[0]&&s1[1]==s2[1])){
			cout<<"1000";
		}else{
			if(check(s1)!=check(s2)){
				cout<<"1100";
			}else{
				int minus=s1[2]-s2[2];
				if(minus==1||minus==-1){
					cout<<"1111";
				}else cout<<"1110";
			}
		}
	}
	return 0;
} 
