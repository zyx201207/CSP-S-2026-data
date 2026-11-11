#include<bits/stdc++.h>
using namespace std;
int n,m,a[205];
string s1,s2,s3,s4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1;
	cin>>s2;
	cin>>s3;
	cin>>s4;
	a['A']=3,a['B']=6,a['C']=9,a['D']=2,a['F']=5;
	if(s1==s3){
		if(s2[0]==s4[0]&&s2[1]==s4[1]){
			if(a[int(s2[2])]%3==a[int(s4[2])]%3){
				if(abs(a[int(s2[2])]-a[int(s4[2])])==3)cout<<"1111";
				else cout<<"1110";
			}else cout<<"1100";
		}else cout<<"1000";
	}else cout<<"0000";
	return 0;
}
