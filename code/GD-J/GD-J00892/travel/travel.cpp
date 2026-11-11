#include<bits/stdc++.h>
#define int long long
using namespace std;
int x,y;
string s1,s2;
bool a=0,b=0,c=0;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x>>s1>>y>>s2;
	if(x==y){
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
		a=1;
		if(s1[2]<='C'&&s2[2]<='C'){
			if(abs(s1[2]-s2[2])==1) c=1;
				b=1;
			} 
			else if(s1[2]>='D'&&s2[2]>='D'){
				if(abs(s1[2]-s2[2])==1) c=1;
				b=1;
			}
		} 
	} 
	
	cout<<(x==y)<<a<<b<<c;
	return 0;
} 
