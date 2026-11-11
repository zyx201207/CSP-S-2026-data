#include<bits/stdc++.h>
using namespace std;
string s;
char c;
long long n,m,l,ans=LLONG_MAX,z;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m>>c;
		l+=m;
		for(int j=1;j<=m;j++)s+=c;
	}l-=1;
	long long num=0,cnt=-1;
	while(num<=s.size()){
		if(s[num]!=s[s.size()-num+1]) cnt+=1;
		num+=1;
		
	}cout<<cnt/2;
	return 0;
}