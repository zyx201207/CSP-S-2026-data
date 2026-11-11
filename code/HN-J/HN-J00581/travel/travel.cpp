#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<"1";
			int k1=min(s1[2]-'A',s2[2]-'A'),k2=max(s1[2]-'A',s2[2]-'A');
			if(k1==0&&k2==1||k1==0&&k2==2||k1==1&&k2==2||k1==3&&k1==5){
				cout<<"1";
				if(k2-k1==1&&k1!=2||k1==3&&k2==5){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
} 
