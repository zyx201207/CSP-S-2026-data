#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		string p1,p2;
		for(int i=0;i<3;i++){
			if(s1[i]>='0'&&s1[i]<='9')p1+=s1[i];
			if(s2[i]>='0'&&s2[i]<='9')p2+=s2[i];
		}
		if(p1==p2)cout<<"1";
		else{
			cout<<"000";
			return 0;
		}
		if((s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'))cout<<"1";
		else if((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F'))cout<<"1";
		else {
			cout<<"00";
			return 0;
		}
		if((s1[2]==s2[2]+1)||(s1[2]==s2[2]-1))cout<<"1";
		else cout<<"0";	
	}else{
		cout<<"0000";
	}
	return 0;
}
