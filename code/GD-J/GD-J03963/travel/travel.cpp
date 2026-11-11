#include <bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int cnt1,cnt2,cnt3,cnt4;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> s1>>s2>>s3>>s4;
	if(s1==s3)cnt1=1;
	if(s2[0]==s4[0]&&s2[1]==s4[1]){
		cnt2=1;
		if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
			if(s4[2]=='A'||s4[2]=='B'||s4[2]=='C'){
				cnt3=1;
				if((s2[2]=='A'&&s4[2]=='B')||(s2[2]=='B'&&s4[2]=='C')||(s4[2]=='A'&&s2[2]=='B')||(s4[2]=='B'&&s2[2]=='C'))cnt4=1;
			}
		}
		else if(s2[2]=='D'||s2[2]=='F'){
			if(s4[2]=='D'||s4[2]=='F'){
				cnt3=1;
				if((s2[2]=='D'&&s4[2]=='F')||(s4[2]=='D'&&s4[2]=='F'))cnt4=1;
			}
		}
	}
	cout << cnt1<<cnt2<<cnt3<<cnt4;
}
