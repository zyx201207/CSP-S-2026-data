#include<bits/stdc++.h>
using namespace std;

struct node{
	long long num;
	char x;
}s[200010];
string S;
long long n,g,ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i].num>>s[i].x;
		if(i==1)g=s[i].num;
		g=__gcd(g,s[i].num);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=(s[i].num/g);j++)S+=s[i].x;
	}
	for(int i=0;i<S.size()/2;i++)if(S[i]!=S[S.size()-1-i])ans+=g;
	cout<<ans;
}
