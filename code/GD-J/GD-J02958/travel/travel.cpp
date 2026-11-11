#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000"<<endl;
		return 0;
	}
	else{
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<"11";
			if(((s1[2]>='A'&&s1[2]<='C')&&(s2[2]>='A'&&s2[2]<='C'))||((s1[2]>='D'&&s1[2]<='E')&&(s2[2]>='D'&&s2[2]<='E'))){
				cout<<"1";
				if(s1[2]=='C'&&s2[2]=='D'){
					cout<<"0"<<endl;
					return 0;
				}
				else if(abs(s1[2]-s2[2])==1){
					cout<<"1"<<endl;
					return 0;
				}
				else{
					cout<<"0"<<endl;
					return 0;
				}
			}
			else{
				cout<<"00"<<endl;
			}
		}
		else{
			cout<<"1000"<<endl;
			return 0;
		}
	}
	return 0;
}
//((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))||((s1[2]=='D'||s1[2]=='E')&&(s2[2]=='D'||s2[2]=='E'))
