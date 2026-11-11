#include<bits/stdc++.h>
using namespace std;
string x,y;
string s1,s2,c1,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>c1>>c2;
	if(s1!=c1){
		cout<<"0000";
	}else{
		x+=s2[0];x+=s2[1];
		y+=c2[0],y+=c2[1];
		if(x!=y){
			cout<<"1000";
		}else{
			char a=s2[2],b=c2[2];
			if(a<='C'&&b>='D'){
				cout<<"1100";
			}else{
				if(abs(a-b)==1){
					cout<<"1111";
				}else{
					cout<<"1110";
				}
			}
		}
	}
	cout<<endl;
	return 0;
}
