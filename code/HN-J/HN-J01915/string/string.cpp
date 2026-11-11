#include<bits/stdc++.h>
#define ll long long 
using namespace std;
string s=" ";
ll n,l,ans;
char k; 
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
 	cin>>n;
	for(int i=1;i<=n;i++){
		scanf("%lld",&l);
		cin>>k;
		for(int j=1;j<=l;j++) s+=k;
	}
	l=s.size();
	for(int i=1;i<=(l-1)/2;i++) if(s[i]!=s[l-i+1]) ans++;
	printf("lld\n",ans);
	return 0;
} 
