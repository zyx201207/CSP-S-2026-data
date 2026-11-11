//GZ-J00278 章茂辰 贵阳市南明区李端棻中学 
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;


int main(){
	ios::sync_with_stdio((0));
	cin.tie((0));
	cout.tie((0));
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	int h1=(s1[0]-'0')*10+(s1[1]-'0');
	int h2=(s2[0]-'0')*10+(s2[1]-'0');
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}else{
		cout<<"1";
		if(h1!=h2){
			cout<<"000";
			return 0;
		}else{
			cout<<"1";
			if( !( ( ( s1[2]>='A'&&s1[2]<='C') && (s2[2]>='A'&&s2[2]<='C') )  ||
			( ( s1[2]=='D'||s1[2]=='F') && (s2[2]=='F'||s2[2]=='D') ) ) ){
				cout<<"00";
				return 0;
			}else{
				cout<<"1";
				if(( s1[2]=='D'||s1[2]=='F') && (s2[2]=='F'||s2[2]=='D') ){
					cout<<"1";
					return 0;
				}
				if(s1[2]=='B'||s2[2]=='B'){
					cout<<"1";
					return 0;
				}
				cout<<'0';
				
			}
			
		}
	}
	
	return 0;
}

