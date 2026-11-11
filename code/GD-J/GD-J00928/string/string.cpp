#include<bits/stdc++.h>
using namespace std;
char c;
long long n,a;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		while(a--)s+=c;
	}
	long long ans=0,l=s.size();
	for(int i=0,j=l-1;i<=j;i++,j--){
		if(s[i]!=s[j])ans++;
	}
	cout<<ans;
	return 0;
} 
