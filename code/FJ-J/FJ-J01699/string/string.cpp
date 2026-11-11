#include<bits/stdc++.h>
using namespace std;
int n,a;
char c,s[100000005];
long long cnt=1,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		s[cnt]=c;
		cnt+=a;
	}
	for(int i=1;i<cnt;i++){
		if(s[i]==0) s[i]=s[i-1];
	}
	for(int i=1;i<=(cnt-1)/2;i++){
		if(s[i]==s[cnt-i]) continue;
		ans++;
	}
	cout<<ans;
	return 0;
} 
