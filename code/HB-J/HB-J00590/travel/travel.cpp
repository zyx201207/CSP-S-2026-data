#include <bits/stdc++.h>
using namespace std;
string  c1,s1,c2,s2;
int ans;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >>c1>>s1>>c2>>s2;
	if(c1==c2){
		ans+=1000;
		if(s1[1]+s1[0]==s2[1]+s2[0]){
			ans+=100;
			if(s1[2]=='A'&&s2[2]=='C'||s1[2]=='A'&&s2[2]=='B'){
				ans+=10;
				if(s1[2]=='A'&&s2[2]=='B'){
					ans+=1;
				}
			}
			else if(s1[2]=='B'&&s2[2]=='A'||s1[2]=='B'&&s2[2]=='C'){
				ans+=10;
				if(s1[2]=='B'&&s2[2]=='A'){
					ans+=1;
				}
			}
			else if(s1[2]=='C'&&s2[2]=='A'||s1[2]=='C'&&s2[2]=='B'){
				ans+=10;
				if(s1[2]=='C'&&s2[2]=='B'){
					ans+=1;
				}
			}
			else if(s1[2]=='D'&&s2[2]=='F'||s1[2]=='F'&&s2[2]=='D'){
				ans+=11;
			}
		}
	}
	else if(ans==0){
		cout<<"0000";
		return 0;
	}
	cout<<ans;
	return 0;
}
