#include <bits/stdc++.h>
using namespace std;
struct type{
	int k;
	char l;
};
int main(){
	freopen("string.in","r",stdin);
	 freopen("string.out","w",stdout);
	 long long n,num=0;
	 bool flag=1;
	
	 cin>>n;
	 type s[n+1];
	 long long ans=0;
	 for(long long i=1;i<=n;i++){
	 	cin>>s[i].k>>s[i].l;
		num+=s[i].k;
	if(i>=2){
		if(s[i].l!=s[i-1].l)flag=0;
	}
	 }
	 if(flag){
	 	cout<<0;
	 	return 0;
	 }
	  char s2[num+1];
	  long long now=1;
	for(long long i=1;i<=n;i++){
		for(long long j=1;j<=s[i].k;j++){
			s2[now]=s[i].l;
			now++;
		}
	}
	 for(long long i=1;i<=num/2;i++){
	 	if(s2[i]!=s2[num-i])ans++;
	 }
	cout<<ans;
}
