#include<bits/stdc++.h>
using namespace std;
long long a[200010],ans,len,n;
char c;
bool f;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	if(n==1){
		for(int i=1;i<=n;i++)cin>>a[i]>>c;
		cout<<0;
		return 0;
	}
	if(n==2){
		long long x,y;
		char u,v;
		cin>>x>>u>>y>>v;
		if(u!=v)cout<<min(x,y);
		else cout<<0;
		return 0;
	}
	else{
		for(long long i=1;i<=n;i++){
			cin>>a[i]>>c;
			for(long long j=1;j<=a[i];j++)s+=c;
		}
		len=s.size();
		for(long long i=0;i<len/2;i++){
			if(s[i]!=s[len-i-1])ans++;
		}
		cout<<ans;
		return 0;
	}
	return 0;
} 
