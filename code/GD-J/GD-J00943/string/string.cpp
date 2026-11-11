#include<bits/stdc++.h>
using namespace std;
int n,m,cnt=0;
string s,ss;
char x;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;	
	if(n==1)cout<<0;
	for(int i=0;i<n;i++){
		cin>>m>>x;
		for(int i=1;i<=m;i++)s+=x;
	}
	if(s.size()%2==1&&!((s[s.size()/2]==s[s.size()/2+1])&&s[s.size()/2+2]==s[s.size()/2+1])){
		cnt++;
		s[s.size()/2+1]='z';
	}
	ss=s;
	reverse(s.begin(),s.end());
	if(ss==s)cout<<cnt;
	else cout<<cnt+1;
	return 0;
}
