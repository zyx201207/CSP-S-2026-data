#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define u_map unordered_map
const ll N=1e5+10,INF=0x3f3f3f3f,LINF=1e18+1;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(s1[0]+s1[1]==s2[0]+s2[1]){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	char k=s1[2],l=s2[2];
	if(((k>='A'&&k<='C')&&(l>='A'&&l<='C'))){
		cout<<1;
		if((k=='A'&&l=='B')||(k=='B'&&(l=='A'||l=='C'))||(k=='B'&&l=='C')){
			cout<<1;
		}else{
			cout<<0;
		}
	}else if((k=='D'&&l=='F')||(k=='F'&&l=='D')){
		cout<<11;
		return 0;
	}else{
		cout<<"00";
	}
	return 0;
}
