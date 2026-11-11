#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
char a[5]={'A','B','C'};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<"1";
			bool f1=0,f2=0;
			for(int i=0;i<3;i++){
				if(s1[2]==a[i])	f1=1;
				if(s2[2]==a[i])	f2=1;
			}
			if(f1==f2){
				cout<<"1";
				if(f1==0){
					cout<<"1";
				}
				else if(abs(s1[2]-s2[2])==1){
					cout<<"1";
				}
				else	cout<<"0";
			}
			else	cout<<"00";
		}
		else	cout<<"000";
	}
	else	cout<<"0000";
	return 0;
}
