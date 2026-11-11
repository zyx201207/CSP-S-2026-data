#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(NULL);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int cnt=0;
	if(c1[0]==c2[0] && c1[1]==c2[1]){
		cout<<1;
		cnt++;
	}else{
		cout<<0;
	}
	if(s1[0]==s2[0] && s1[1]==s2[1] && cnt==1){
		cout<<1;
		cnt++;
	}else{
		cout<<0;
	}
	if(s1[2]=='D' && s2[2]=='F' && cnt==2){
		cout<<11;
		return 0;
	}
	if(s1[2]=='F' && s2[2]=='D' && cnt==2){
		cout<<11;
		return 0;
	}
	if(s1[2]-'C'<='0' && s2[2]-'C'<='0' && cnt==2){
		cout<<1;
		if(s1[2]-1==s2[2] || s2[2]-1==s1[2]){
			cout<<1;
			return 0;
		}else{
			cout<<0;
			return 0;
		}
	}else{
		if(cnt==2){
			cout<<1; 
			if(s1[2]=='D' || s2[2]=='D'){
				cout<<1;
				return 0;
			}else{
				cout<<0;
			} 
		}
	}
	return 0;
}
