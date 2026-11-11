#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,ans=0;
	string s="";
	cin>>n;
	for(int i=1;i<=n;i++){
		long long ai;
		string ci;
		cin>>ai>>ci;
		for(int i=1;i<=ai;i++)s+=ci;
	}
	int i=0,j=s.size()-1;
	for(i;i<j;i++){
		if(s[i]!=s[j])ans++;
		j--;
	}
	cout<<ans;
	return 0;
}
