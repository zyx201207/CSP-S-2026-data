#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int x,y;
	string s,s2;
	cin>>x>>s>>y>>s2;
	if(x==y){
		cout<<1;
		if(s[0]==s2[0]&&s[1]==s2[1]){
			cout<<1;
			bool flag=(s[2]=='A'||s[2]=='B'||s[2]=='C'),flag2=(s2[2]=='A'||s2[2]=='B'||s2[2]=='C');
			if(flag==flag2){
				cout<<1;
				if(abs(s[2]-s2[2])==1||(s[2]=='D'&&s2[2]=='F')||(s[2]=='F'||s2[2]=='D'))cout<<"1\n";
				else cout<<"0\n";
			}else cout<<"00\n";
		}else cout<<"000\n";
	}else cout<<"0000\n";
	return 0;
}

