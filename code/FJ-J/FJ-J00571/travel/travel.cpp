#include <bits/stdc++.h> 
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);//s1[2] s2[2]
	cin.tie(nullptr);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	if(s1[2]=='A'){
		if(s2[2]=='B'){
			cout<<"11";
		}else if(s2[2]=='C'){
		    cout<<"10";
		}else{
			cout<<"00";
		}
	}else if(s1[2]=='B'){
		if(s2[2]=='A'){
			cout<<"11";
		}else if(s2[2]=='C'){
		    cout<<"11";
		}else{
			cout<<"00";
		}
       }else if(s1[2]=='C'){
		if(s2[2]=='A'){
			cout<<"10";
		}else if(s2[2]=='B'){
		    cout<<"11";
		}else{
			cout<<"00";
		}
       }else if(s1[2]=='D'){
		if(s2[2]=='F'){
			cout<<"11";
		}else{
			cout<<"00";
		}
       }else if(s1[2]=='F'){
		if(s2[2]=='D'){
			cout<<"11";
		}else{
			cout<<"00";
		}
       }
	return 0;
}
