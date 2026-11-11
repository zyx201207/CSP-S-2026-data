#include<bits/stdc++.h>
using namespace std;
string s;
string ss;
string sss;
int cnt;
int cnnt;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char c;
		cin>>x>>c;
		for(int j=1;i<=x;j++){
			s+=c;
		}
	}
	for(int i=0;i<int(s.size()-1)/2;i++){
		ss+=s[i];
	}
	sss=ss;
	reverse(ss.begin(),ss.end());
	sss+=ss;
	for(int i=0;i<int(s.size());i++){
		if(sss[i]!=s[i])cnt++;
	}
	ss="";
	sss="";
	for(int i=(s.size()-1)/2;i>0;i--){
		ss+=s[i];
	}
	sss=ss;
	reverse(ss.begin(),ss.end());
	ss+=sss;
	for(int i=0;i<int(s.size());i++){
		if(sss[i]!=s[i])cnnt++;
	}
	cout<<min(cnt,cnnt);
}  
