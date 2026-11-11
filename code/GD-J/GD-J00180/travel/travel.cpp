#include<bits/stdc++.h>
#define int long long
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;

const int maxn=1e5+5;

string c1,s1,c2,s2;

signed main() {
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>c1>>s1>>c2>>s2;
	
	if(c1==c2) {
		
		cout<<1;
		
		if(s1[0]==s2[0]&&s1[1]==s2[1]) {
			
			cout<<1;
			
			int num1=s1[2]-'A'+1,num2=s2[2]-'A'+1;
			
			if((num1<=3&&num2<=3)||(num1>3&&num2>3)) {
				
				cout<<1;
				
				if(abs(num1-num2)==1) cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	
	return 0;
}
