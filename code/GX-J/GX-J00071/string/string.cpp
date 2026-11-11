#include<bits/stdc++.h>
using namespace std;
string a[200005];
int b[200005];
int n;
int ans=0;
int sz;
string zm;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>sz;
		cin>>zm;
		while(sz--)s=s+zm;
	}
	int l=s.size();
	for(int i=0;i<l;i++)
	{
		if(s[i]!=s[l-i-1])ans++;
	}
	cout<<ans;


	return 0;
}
