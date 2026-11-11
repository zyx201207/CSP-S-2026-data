#include<bits/stdc++.h>
using namespace std;
int const N=1e9+4;
char s[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;cin>>n;
	long long cnt=0,ans=0;	
	for(int i=1;i<=n;i++){
		int a;char c;
		cin>>a>>c;
		for(int j=cnt+1;j<=cnt+a;j++){
			s[j]=c;
		}
		cnt+=a;
	}
	for(int i=1;i<=cnt/2;i++){
		if(s[i]!=s[cnt-i+1])ans++;
	}cout<<ans;
	return 0;
}
