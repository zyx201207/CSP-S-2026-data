#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool is_true[6];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int cnt1=(s1[0]-'0')+(s1[1]-'0'),cnt2=(s2[0]-'0')+(s2[1]-'0');
	if(c1==c2) {
		is_true[1]=1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(c1==c2 and cnt1==cnt2) {
		is_true[2]=1;	
	}else{
		cout<<"1000";
		return 0;
	}
	if((s1[2]=='A' and s2[2]=='B') or (s1[2]=='A' and s2[2]=='C') or (s1[2]=='B' and s2[2]=='A') or (s1[2]=='B' and s2[2]=='C') or (s1[2]=='C' and s2[2]=='A') or (s1[2]=='C' and s2[2]=='B') or (s1[2]=='D' and s2[2]=='F') or (s1[2]=='F' and s2[2]=='D'))
		is_true[3]=1;	
		else{
		cout<<"1100";
		return 0;
	}
	if(abs(s1[2]-s2[2])==1){
		is_true[4]=1;
	}else{
		cout<<"1110";
		return 0;
	}
	for(int i=1;i<=4;i++) cout<<is_true[i];
	return 0;
}
