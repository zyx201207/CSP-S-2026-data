#include<bits/stdc++.h>
using namespace std;
int n,a[200010],ans=0;
char s[200010];
string s2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>s[i];
		for(int j=1;j<=a[i];j++){
			s2+=s[i];
		}
	}for(int i=0;i<s2.size()/2;i++){
		if(s2[i]!=s2[s2.size()-i-1])ans++;
		
	}cout<<ans;
	return 0;
}
