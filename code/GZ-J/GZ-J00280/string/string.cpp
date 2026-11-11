//GZ-J00280 周润泽 贵阳市第三实验中学 
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7; 
int n;
string t;
string s1="",s2="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		long long x;
		string s;
		cin>>x>>s;
		while(x--)t+=s;
	}
	int x;
	if(t.size()/2==0)x=t.size()/2;
	else x=t.size()/2+1;
	for(int i=0;i<x;i++)s1+=t[i];
	for(int i=t.size()-1;i>=x-1;i--)s2+=t[i];
	if(s1==s2){
		cout<<0;
		return 0;
	}
	int ans=0;
	for(int i=0;i<x;i++){
		if(s1[i]!=s2[i])ans++;
	}
	cout<<ans;
	return 0;
}
