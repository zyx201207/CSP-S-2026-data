#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}else{
		cout<<1;
//		string a=s1[0]+s1[1];
//		string b=s2[0]+s2[1];
//	cout<<s1[1]<<s2[1];
		if(s1[0]!=s2[0]||s1[1]!=s2[1]){
			cout<<"000";
			return 0;
		}else{
			cout<<1;
			char c=s1[2];
			char d=s2[2];
			if(!((c<='C'&&d<='C')||(c>'C'&&d>'C'))){
				cout<<"00";
				return 0;
			}else{
				cout<<1;
				if((c=='A'&&d=='C')||(c=='C'&&d=='A')) cout<<1;
				else cout<<0;
			}
		}
	}
	return 0;
} 
