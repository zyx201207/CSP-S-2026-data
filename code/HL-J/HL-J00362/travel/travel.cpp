#include <bits/stdc++.h>
using namespace std;

string c1,s1,c2,s2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	cin>>c1>>s1>>c2>>s2;
	
	int ca=0,cb=0,sa=0,ssa=0,sb=0,ssb=0;
	for(int i=0;i<c1.size();i++) ca=ca*10+(c1[i]-'0');
	for(int i=0;i<c2.size();i++) cb=cb*10+(c2[i]-'0');
	
	for(int i=0;i<2;i++) sa=sa*10+(s1[i]-'0');
	for(int i=0;i<2;i++) sb=sb*10+(s2[i]-'0');
	
	ssa=s1[2]-'A'+1;
	ssb=s2[2]-'A'+1;
	
	if(ca==cb) cout<<"1";
	else{
		cout<<"0000";
		return 0;
	}
	
	if(sa==sb) cout<<"1";
	else{
		cout<<"000";
		return 0;
	}
	
	if((ssa<=3&&ssb<=3)||(ssa>=4&&ssb>=4)) cout<<"1";
	else{
		cout<<"00";
		return 0;
	}
	
	if(abs(ssa-ssb)==1) cout<<"1";
	else cout<<"0";
	
	return 0;
} 
