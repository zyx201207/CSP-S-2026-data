#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<'1';
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			if(('A'<=s1[2]&&s1[2]<='C'&&'A'<=s2[2]&&s2[2]<='C')||('D'<=s1[2]&&s1[2]<='F'&&'D'<=s2[2]&&s2[2]<='F')){
				cout<<1;
				if(max(s1[2],s2[2])-min(s1[2],s2[2])==1){
					cout<<1;
				}
				else{
					cout<<0;
				}
			}
			else{
				cout<<"00";
				
			}
		}
		else{
			cout<<"00";
			int x=0,y=0;
			for(int i=0;i<=1;i++){
				x=x*10+s1[i];
				y=y*10+s2[i];
			}
			if(max(x,y)-min(x,y)==1&&s1[2]==s2[2]){
				cout<<1;
			}
			else{
				cout<<0;
			}
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
}
