#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,ans;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){//同车厢 
		ans+='1';
		string as=s1.substr(0,2);
		string ds=s2.substr(0,2);
		if(as==ds){//同排座位 
			ans+='1';
			if((s1[2]=='A' and (s2[2]=='B' or s2[2]=='C'))
			or (s1[2]=='B' and (s2[2]=='A' or s2[2]=='C'))
			or (s1[2]=='C' and (s2[2]=='A' or s2[2]=='B'))
			or (s1[2]=='D' and s2[2]=='F')
			or (s1[2]=='F' and s2[2]=='D')){//过道同侧 
				ans+='1';
				if((s1[2]=='A' and s2[2]=='B')
				or (s1[2]=='B' and (s2[2]=='A' or s2[2]=='C'))
				or (s1[2]=='C' and s2[2]=='B')
				or (s1[2]=='D' and s2[2]=='F')
				or (s1[2]=='F' and s2[2]=='D')){//相邻座位 
					ans+='1'; 
				}
				else{
					ans="1110";
				}
			}
			else{
				ans="1100";
			} 
		}
		else{
			ans="1000";
		}
	}
	else{
		ans="0000";
	}
	cout<<ans;
	return 0;
} 
