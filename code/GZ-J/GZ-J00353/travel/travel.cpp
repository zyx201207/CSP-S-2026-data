#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(c1==c2){
		int ss1=0,ss2=0;
		int t=1;
		for(int i=0;i<s1.size();i++){
			if(s1[i]-'0'<=9 && s1[i]-'0'>=0){
				ss1+=(s1[i]-'0') * t;
				t *= 10;
			}
		}
		t=1;
		for(int i=0;i<s1.size();i++){
			if(s2[i]-'0'<=9 && s2[i]-'0'>=0){
				ss2+=(s2[i]-'0') * t;
				t *= 10;
			}
		}
		if(ss1==ss2) cout<<1;
		else{
			cout<<"000";
			return 0;
		}
		int f=0;
		if(ss1==ss2){
			if(s1[s1.size()-1] >= 'D' && s1[s1.size()-1] <= 'F'){
				if(s2[s2.size()-1] >= 'D' && s2[s2.size()-1] <= 'F'){
					cout<<1;
					f=1;
				}
				else{
					cout<<"00";
					return 0;
				}
			}
			else if(s1[s1.size()-1] >= 'A' && s1[s1.size()-1] <= 'C'){
				if(s2[s2.size()-1] >= 'A' && s2[s2.size()-1] <= 'C'){
					cout<<1;
					f=1;
		   		}
				else{
					cout<<"00";
					return 0;
				}
			}
			if(f==1 && abs(s1[2]-s2[2])<=1) cout<<1;
			else cout<<0;
		}
	}
	return 0;
}
