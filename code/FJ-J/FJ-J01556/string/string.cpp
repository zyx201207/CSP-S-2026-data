#include<bits/stdc++.h>
using namespace std;
string sf(int x,char c){
	string s="";
	for(int i=1;i<=x;i++){
		s+=c;
	}
	return s;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdin);
	char c;
	string s="";
	int n,x,t,m=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>c;
		s+=sf(x,c);
	}
	//cout<<s;
	t=s.size();
	for(int i=0;i<t/2;i++){
	    if(s[i]!=s[t-i-1]){
	    	m++;
		}
	}
	cout<<m;
	return 0;
}
