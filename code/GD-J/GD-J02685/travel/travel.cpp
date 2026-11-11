#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]) cout<<1;
	    else cout<<0;
	    
	    if(s1[0]==s2[0]&&s1[1]==s2[1]){
		    if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D')) cout<<1;
		    else cout<<0;
	    }
		else cout<<0;
		
		if(s1[2]<='C'&&s2[2]<='C'){
			int a=(s1[0]-'0')*10+(s1[1]-'0');
			int b=(s2[0]-'0')*10+(s2[1]-'0');
			if(a==b&&s1[2]+1==s2[2]||s1[2]==s2[2]){
				cout<<1;
				return 0;
			}
			else if((a+1==b||a-1==b)&&s1[2]==s2[2]){
				cout<<1;
				return 0;
			}
		}
		
		if(s1[2]>='D'&&s2[2]>='D'){
			int a=(s1[0]-'0')*10+(s1[1]-'0');
			int b=(s2[0]-'0')*10+(s2[1]-'0');
			if(a==b&&s1[2]+1==s2[2]||s1[2]==s2[2]){
				cout<<1;
				return 0;
			}
			else if((a+1==b||a-1==b)&&s1[2]==s2[2]){
				cout<<1;
				return 0;
			}
		}
		cout<<0;
	}
	else cout<<"0000";
	
	return 0;
}
