#include<bits/stdc++.h>
using namespace std;
string s,c,a,b;
int main(){
	freopen("travel3.in","r",stdin);
	freopen("travel3.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>a>>s>>b>>c;
	if(a==b){
		cout<<1;
		for(int i=0;i<2;i++){
			if(s[i]!=c[i]){
				cout<<"000";
				return 0; 
			}
		}
		cout<<1;
		int len=s.size();
		int f=c.size();
		if((s[len-1]=='A'||s[len-1]=='B'||s[len-1]=='C')&&(c[f-1]=='A'||c[f-1]=='B'||c[f-1]=='C')){
			cout<<1;
		}else if((s[len-1]=='F'||s[len-1]=='D')&&(c[f-1]=='D'||c[f-1]=='F')){
			cout<<1;
		}else{
			cout<<"00";
			return 0;
		}
		if(s[len-1]+1==c[f-1]||s[len-1]-1==c[f-1]){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}else{
		cout<<"0000";
		return 0;
	}
	
	return 0;
} 
