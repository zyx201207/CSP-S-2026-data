#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in.in","r",stdin);
	freopen("travel.out.out","w",stdout);
	string s1,s2;
	int c1,c2,s5,s6;
	cin>>c1>>s1>>c2>>s2;
	char s3,s4;
	s3=s1[2];
	s4=s2[2];
	s5=s3;
	s6=s4;
	if (c1==c2){
		if(s1[0]==s2[0] and s1[1]==s2[1]){
			if(s5==68 and s6==69 or s5==69 and s6==68 or s5==65 and s6==66 or s5==66 and s6==65 or s5==65 and s6==67 or s5==67 and s6==65 or s5==66 and s6==67 or s5==67 and s6==66){
				if(s5==68 and s6==69 or s5==69 and s6==68 or s5==66 and s6==67 or s5==67 and s6==66 or s5==65 and s6==66 or s5==66 and s6==65 ){
					cout<<"1111";
				}
				else{
					cout<<"1110";
				}
			}
			else{
				cout<<"1100";
			}
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
