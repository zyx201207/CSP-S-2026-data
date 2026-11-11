#include<bits/stdc++.h>
using namespace std;
long long n,a,ans;
char c;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		for(int j=1;j<=a;j++)s+=c;
	}
	int l=0,r=s.size()-1;
	while(l<r){
		if(s[r]!=s[l])ans++;
		r--;
		l++;
	}
	cout<<ans;
	return 0;
}
