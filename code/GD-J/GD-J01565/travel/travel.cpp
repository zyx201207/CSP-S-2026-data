#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string c,cc,s,ss;
	cin>>c>>s>>cc>>ss;
	if(c[0]==cc[0] and c[1]==cc[1]){
		cout<<'1';
		if(s[0]==ss[0] and s[1]==ss[1]){
			cout<<'1';
			if(s[2]<='C' and ss[2]<='C'){
				cout<<'1';
				if((s[2]<'C' and ss[2]<'C') or (s[2]>'A' and ss[2]>'A')){
					cout<<'1';
				}
				else{
					cout<<'0';
				}
			}
			else if(s[2]>='D' and ss[2]>='D'){
				cout<<"11";
			}
			else{
				cout<<"00";
			}
		}
		else{
			cout<<"000";
		}
	}
	else{
		cout<<"0000";
	}
	return 0;
} 
