#include<bits/stdc++.h>
using namespace std;
long long a[200010];
char c[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	string s="";
	bool f=1;
	for(int i=0;i<n;i++){
		cin>>a[i]>>c[i];
		for(int j=0;j<a[i];j++)s+=c[i];
		if(c[i]!=c[i-1])f=0;
	}
	//cout<<s;
	if(f==1){cout<<0;return 0;}
	long long ans=0;
	if(s.size()%2==1){
		for(int i=s.size()/2+1;i<s.size();i++){
			if(s[i]!=s[s.size()-i-1])ans++;
		}
	}else{
		for(int i=s.size()/2;i<s.size();i++){
			if(s[i]!=s[s.size()-i-1])ans++;
		}
	}
	cout<<ans;
	return 0;
}

