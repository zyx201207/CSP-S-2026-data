#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c,cc,b=0;
	string s,ss;
	cin>>c>>s>>cc>>ss;
	if(c!=cc){
		cout<<"0000";
		return 0;
		
	}
	
	if(s[0]==ss[0]&&s[1]==ss[1]){
		b+=100;
		if((s[2]<=67&&ss[2]<=67)||(s[2]>67&&ss[2]>67)){
			b+=10;
			int x=max(s[2],ss[2]);
			int n=min(s[2],ss[2]);
			if(n+1==x){
				b+=1;
				cout<<"1111";
				
				
			}
			else{
				cout<<"1110";
			}
		}
		else{
			cout<<"1100";
		}
	}
	else{
		cout<<"1000";
	}
	
	
	
	
	return 0;
}
