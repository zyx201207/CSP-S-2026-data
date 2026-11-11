#include<bits/stdc++.h>
using namespace std;
long long n,a,len,ans;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	while(n--){
		cin>>a>>c;
		while(a--)s+=c;
	}
	len=s.length();
	for(int i=0;i<(len+1)/2;i++){
		if(s[i]!=s[len-i-1])ans++;
	}
	cout<<len<<' '<<ans;
}
