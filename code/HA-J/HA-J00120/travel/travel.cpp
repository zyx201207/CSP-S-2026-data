#include<bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int cnt[10];
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) {
		cnt[1]=1;
		if(s1[1]==s2[1]&&s1[0]==s2[0]) {
			cnt[2]=1;
			if(s1[2]=='C'&&s2[2]=='D'||s1[2]=='D'&&s2[2]=='C') {
				cnt[3]=0;
				cnt[4]=0;				
			}else{
				cnt[3]=1;
				if(s1[2]==s2[2]+1||s1[2]+1==s2[2]) {
					cnt[4]=1;
				}
			} 
		}
	} else {
		cout<<"0000";
	return 0;
	}
	for(int i=1;i<=4;i++){
		cout<<cnt[i];
	}
	return 0;
}
