#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+10,M=1e7+10;
int n,a[N],ans;
char c[N];
string s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		for(int j=1;j<=a[i];j++)
			s=s+c[i];
	}
	string str=s,str1="",str2="";
	reverse(str.begin(),str.end());
	if(s==str){
		cout<<0;
		return 0;
	}
	for(int i=1;i<=s.size()/2;i++)
		str1=str1+s[i];
	for(int i=s.size()/2+1;i<=s.size();i++)
		str2=str2+s[i];
	reverse(str2.begin(),str2.end());
	for(int i=0;i<str1.size();i++)
		if(str1[i]!=str2[i])ans++;
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
