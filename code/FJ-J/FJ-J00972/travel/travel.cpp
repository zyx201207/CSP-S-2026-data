#include<bits/stdc++.h>
using namespace std;
int n,m;
string s,s1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out ","w",stdout);
	cin>>n>>s>>m>>s1;
	if(n==m){
		cout<<1;
		if(s[0]==s1[0]&&s[1]==s1[1]){
			cout<<1;
			char c,d;
			c=s[2],d=s1[2];
			if(c<='C'&&d<='C'){
				cout<<1;
				if(c-1==d||c+1==d)cout<<1;
				else cout<<0;
			}
			else{
				if(c>='D'&&d>='D')cout<<1<<1;
				else cout<<0<<0;
			}
		}
		else cout<<0<<0<<0;
	}
	else cout<<0<<0<<0<<0;
	cout<<"\n";
	return 0;
}
