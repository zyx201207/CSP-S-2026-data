#include<bits/stdc++.h>
using namespace std;
long long n,a,sum=0,ans=0;
char c;
string s="*",t="*";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a;
		
		cin>>c;
		while(a--)s+=c,t=c+t;
	}
	int len =s.size();
	for(int i=1;i<=len-1;i++){
		if(s[i]!=t[i])ans++;;
	}
	cout<<ans;
	return 0;
}
