#include<bits/stdc++.h>
using namespace std;
string s;
long long l,ans=0,n;
bool all=true,first=true;
char last;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout); 
	cin>>n;
	s+='0';
	for(int i=1;i<=n;i++){
		int x;
		char a;
		cin>>x>>a;
		if(first){
			last=a;
			first=false;
		}
		if(!first){
			all=(a==last);
		}
		l+=x;
		for(int i=1;i<=x;i++)s+=a;
	}
	if(all){
		cout<<0<<'\n';
		return 0;
	}
	for(int i=1;i<=l/2;i++){
		if(s[i]!=s[l+1-i])ans++;
	}
	cout<<ans<<'\n';
	return 0;
} 
