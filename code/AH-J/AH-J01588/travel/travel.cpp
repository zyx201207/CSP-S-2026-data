#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie();
	cout.tie();
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		if((s1[0]==s2[0])&&(s1[1]==s2[1])){
			cout<<"1";
			int a1=s1[2]-'A',a2=s2[2]-'A';
			if((a1>=0 && a1<=2 && (a2==3)||(a2==4)) || (a2>=0 && a2<=2 && (a1==3)||(a1==4))){
				cout<<"00";
			}
			else{
				if(((a1-a2)==1) || ((a1-a2)==-1)){
					cout<<"11";
				}
				else{
					cout<<"10";
				}
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
