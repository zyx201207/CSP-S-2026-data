#include<bits/stdc++.h>
using namespace std;
long long n,x,len=0,ans=0,a[27]={0},maxx=-1;
char c;
string s="";
bool f=1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>x>>c;
		a[c-97]++;
		for(long long k=1;k<=x;k++){
			s=s+c;
		}
		len+=x;
		if(x!=1)f=0;
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	for(int i=0;i<26;i++){
		maxx=max(maxx,a[i]);
	}
	if(f){
		for(long long i=0,j=n-1;i<=n/2;i++,j--){
			if(s[i]!=s[j])ans++;
		}
		cout<<ans;
	}
	else{
		for(long long i=0,j=len-1;i<=len/2;i++,j--){
			if(s[i]!=s[j])ans++;
		}
		cout<<ans;
	}
	return 0;
}
