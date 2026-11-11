#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		if(((s1[0]-48)*10+(s1[1]-48))==((s2[0]-48)*10+(s2[1]-48))){
			cout<<"1";
			bool p1,p2;
			p1=(s1[2]<='C'&&s2[2]<='C');
			p2=(s1[2]>='D'&&s2[2]>='D');
			if(p1||p2){
				cout<<"1";
				if(s1[2]+1==s2[2]){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
} 
