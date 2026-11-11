#include<bits/stdc++.h>
#define int long long
using namespace std;
string s1,s2,s3,s4;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}if(s2[0]==s4[0]&&s2[1]==s4[1]){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}switch(s2[2]){
		case 'A':{
			if(s4[2]=='B'||s4[2]=='C')cout<<1;
			else{
				cout<<"00";
				return 0;
			}break;
		}case 'B':{
			if(s4[2]=='A'||s4[2]=='C')cout<<1;
			else{
				cout<<"00";
				return 0;
			}break;
		}case 'C':{
			if(s4[2]=='A'||s4[2]=='B')cout<<1;
			else{
				cout<<"00";
				return 0;
			}break;
		}case 'D':{
			if(s4[2]=='F')cout<<1;
			else{
				cout<<"00";
				return 0;
			}break;
		}case 'F':{
			if(s4[2]=='D')cout<<1;
			else{
				cout<<"00";
				return 0;
			}break;
		}
	}switch(s2[2]){
		case 'A':{
			cout<<((s4[2]=='B')?1:0);
			break;
		}case 'B':{
			cout<<((s4[2]=='A'||s4[2]=='C')?1:0);
			break;
		}case 'C':{
			cout<<((s4[2]=='B')?1:0);
			break;
		}case 'D':{
			cout<<((s4[2]=='F')?1:0);
			break;
		}case 'F':{
			cout<<((s4[2]=='D')?1:0);
			break;
		}
	}return 0;
}
