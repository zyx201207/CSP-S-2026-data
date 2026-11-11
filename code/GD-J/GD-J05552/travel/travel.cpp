#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen('travel.in','r',stdin);
	freopen('travel.out','r',stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c1,c2;
	string s1,s2;
    cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<0;
	}
	if(s1[0]==s2[0] and s1[1]==s2[1]){
		cout<<1;
	}else{
		cout<<0;
	}
	if(((s1[2]>='A' and s1[2]<='C') and (s2[2]>='A' and s2[2]<='C')) or ((s1[2]=='D' or s1[2]=='F') and (s2[2]=='D' or s2[2]=='F'))){
		cout<<1; 
	}else{
		cout<<0;
	}
	if((s1[2]>='A' and s1[2]<='C') and (s2[2]>='A' and s2[2]<='C') and (s1[2]+1==s2[2] or s1[2]-1==s2[2]) or (s1[2]=='D' or s1[2]=='F') and (s2[2]>='A' and s2[2]<='C') and (s1[2]+2==s2[2] or s1[2]-2==s2[2])){
		cout<<1;
	}else{
		cout<<0;
	}
	return 1;
} 
