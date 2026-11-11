#include <bits/stdc++.h>
using namespace std;
string c,s,c1,s1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>c1>>s1;
	if(c==c1) cout<<1;
	else{
		 cout<<"0000";
		 return 0;
	}
	int flag=0;
	for(int i=0;i<2;i++){
		if(s[i]!=s1[i]){
			flag=1;
			break;
		}
	}
	if(flag==0){
		cout<<1;
		char a=s[2],b=s1[2];
		if((a=='A' || a=='B' || a=='C') && (b=='A' || b=='B' || b=='C')){
			cout<<1;
			if(int(a)+1==int(b) || int(a)-1==int(b)){
				cout<<1;
			}
			else{
				cout<<0;
			}
		}
		else if((a=='D' || a=='F') && (b=='D' || b=='F')){
			cout<<"11";
			return 0;
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
	return 0;
}
