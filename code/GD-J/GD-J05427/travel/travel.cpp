#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int cnt=0; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int lenc1=c1.size();
	int lenc2=c2.size();
	for(int i=0;i<max(lenc1,lenc2);i++){
		if(c1[i]==c2[i]){
			cnt++;
		}
	}
	if(cnt==max(lenc1,lenc2)){
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<"1";
			if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')){
				cout<<"1";
				if((s1[2]+1==s2[2])||(s1[2]-1==s2[2])){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
			else {
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else {
		cout<<"0000";
	}
	return 0;
}
