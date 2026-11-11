#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	//cout<<(s1[0]-'0')*10+(s1[1]-'0')<<endl;
	if((c1[0]-'0')*10+(c1[1]-'0')!=(c2[0]-'0')*10+(c2[1]-'0')){
		cout<<"0000";
	} else {
		cout<<"1";
		if((s1[0]-'0')*10+(s1[1]-'0')!=(s2[0]-'0')*10+(s2[1]-'0')){
			cout<<"000";
		} else {
			cout<<"1";
			if((s1[2]<='C'&&s2[2]>='D')||(s2[2]<='C'&&s1[2]>='D')){
				cout<<"00";
			} else {
				cout<<"1";
				if((s1[2]-s2[2]==1)||(s2[2]-s1[2]==1)){
					cout<<"1";
				} else {
					cout<<"0";
				}
			}
		}
	}
	return 0;
}
/*
02 02A 02 02B
*/
