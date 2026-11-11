#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2,k;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	else{
		k+='1';
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			k+='1';
			if((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='F'&&s2[2]=='D')){
				k+="11";
				cout<<k;
				return 0;
			}else if(s1[2]<='C'&&s2[2]<='C'){
				k+='1';
				if(s1[2]-1==s2[2]||s1[2]+1==s2[2]){
					k+='1';	
				}else k+='0';
			}else k+="00";
		}else{
			k+="000";
		}
	}
	cout<<k;
	return 0;
}
