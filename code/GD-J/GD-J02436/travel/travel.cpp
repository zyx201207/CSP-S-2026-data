#include<bits/stdc++.h>
#define int long long
using namespace std;
string a,b;
char c,s,cc,ss,d,dd;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>a>>c>>cc>>s>>b>>d>>dd>>ss;
	if(a==b){
		if(c==d and cc==dd){
			if(s=='A'){
				if(ss=='B'){
					cout<<"1111";
				}else if(ss=='C'){
					cout<<"1110";
				}else{
					cout<<"1100";
				}
			}else if(s=='B'){
				if(ss=='A' or ss=='C'){
					cout<<"1111";
				}else{
					cout<<"1100";
				}
			}else if(s=='C'){
				if(ss=='B'){
					cout<<"1111";
				}else if(ss=='A'){
					cout<<"1110";
				}else{
					cout<<"1100";
				}
			}else if(s=='D'){
				if(ss=='F'){
					cout<<"1111";
				}else{
					cout<<"1100";
				}
			}else{
				if(ss=='D'){
					cout<<"1111";
				}else{
					cout<<"1100";
				}
			}
		}else{
			cout<<"1000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
