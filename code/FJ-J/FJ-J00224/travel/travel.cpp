#include<bits/stdc++.h>
using namespace std;
string s1,s2,S1,S2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s1>>s2>>S1>>S2;
	if(s1==S1){
		cout<<1;
		char c,C;
		c=s2[s2.size()-1],C=S2[S2.size()-1];
		int f=1;
		for(int i=0;i<s2.size()-1;i++){
			if(s2[i]!=S2[i]){
				f=0;
				break;
			}
		}
		if(f){
			cout<<1;
			if( ((c=='D'||c=='F')&&(C=='A'||C=='B'||C=='C')) || ((C=='D'||C=='F')&&(c=='A'||c=='B'||c=='C')) ) cout<<"00";
			else{
				cout<<1;
				if((C=='D'&&c=='F')||(C=='F'&&c=='D')) cout<<1;
				else if((C=='A'&&c=='B')||(C=='B'&&c=='A')) cout<<1;
				else if((C=='B'&&c=='C')||(C=='C'&&c=='B')) cout<<1;
				else cout<<0;
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
