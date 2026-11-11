#include<bits/stdc++.h>
using namespace std;

bool f(char c1,char c2){
	if(c1=='F' && c2=='D') return 1;
	else if(c1=='D' && c2=='F') return 1;
	
	else if(c1=='C' && c2=='B') return 1;
	else if(c1=='C' && c2=='A') return 1;
	else if(c1=='B' && c2=='A') return 1;
	
	else if(c1=='B' && c2=='C') return 1;
	else if(c1=='A' && c2=='C') return 1;
	else if(c1=='A' && c2=='B') return 1;
	
	else return 0;
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string c1,s1,c2,s2;cin>>c1>>s1>>c2>>s2;
	if(c1!=c2) cout<<"0000"<<'\n';
	else{
		cout<<"1";
		if(s1[0]!=s2[0] || s1[1]!=s2[1]) cout<<"000";
		else{
			cout<<"1";
			if(!f(s1[2],s2[2])) cout<<"00";
			else{
				cout<<"1";
				if(int(s1[2])+1==int(s2[2]) || int(s2[2])+1==int(s1[2])) cout<<"1";
				else cout<<"0";
			}
		} 
	}
	return 0;
} 
