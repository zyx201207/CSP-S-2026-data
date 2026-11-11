#include<bits/stdc++.h>
using namespace std;
string a,b,c,d,ans;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		ans+='1';
		if(b[0]==d[0]&&b[1]==d[1]){
			
			ans+='1';
			if(b[2]<=67&&d[2]>67||b[2]>67&&d[2]<=67) cout<<1100;
			else if(b[2]>=65&&b[2]<=67||d[2]>=65&&d[2]<=67){
					ans+='1';
				
					if(b[2]=='A'&&d[2]=='C'||b[2]=='C'&&d[2]=='A'){
						cout<<1110;
					} 
				
					else cout<<1111;
			}
			
			else if(b[2]=='D'&&d[2]=='F'||b[2]=='F'&&d[2]=='D') cout<<1111;
			
		}
		else cout<<1000;
	}
	else{
		cout<<"0000";
	}
	return 0;
}
