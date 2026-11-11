#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int side(char x,char y){
	if('A'<=x&&x<='C'){
		if('A'<=y&&y<='C'){
			return 1;
		}
		else return 0;
	}
	if('D'<=x&&x<='F'){
		if('D'<=y&&y<='F'){
			return 1;
		}
		else return 0;
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if((c1[0]-'0')*10+c1[1]-'0'==(c2[0]-'0')*10+c2[1]-'0'){
    	cout<<1;
    	if((s1[0]-'0')*10+s1[1]-'0'==(s2[0]-'0')*10+s2[1]-'0'){
    		cout<<1;
    		if(side(s1[2],s2[2])){
    			cout<<1;
    			if(s1[2]+1==s2[2]||s1[2]-1==s2[2]){
    				cout<<1;
				}
				else{
					cout<<0;
					return 0;
				}
			}
			else{
				cout<<"00";
				return 0;
			}
		}
		else{
			cout<<"000";
			return 0;
		}
	}
	else{
		cout<<"0000";
		return 0;
	}
	return 0;
}
