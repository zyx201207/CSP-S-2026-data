#include<bits/stdc++.h>
using namespace std;
#define int long long
string c1,c2,s1,s2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>s1>>s2;
	if(c1==s1){
		if(c2[0]==s2[0] && c2[1]==s2[1]){
			if(c2[2]=='F' && s2[2]=='D' || (c2[2]!='D' && c2[2]!='F') && (s2[2]!='D' && s2[2]!='F')){
				int x=c2[2],y=s2[2];
				int ans=abs(x-y);
				if((c2[2]!='D' && s2[2]!='C' && c2[2]!='C' && s2[2]!='D') && ans<=1){
					cout<<"1111";
				}
				else cout<<"1110";
			}
			else cout<<"1100";
		}
		else cout<<"1000";
	}
	else cout<<"0000";
	return 0;
}
