#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,ans,ans2;
string s;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int a;
		char c;
		cin>>a>>c;
		for(int i=1;i<=a;i++){
			s+=c;
		}
	}
	int m=s.size();
	for(int i=0;i<m/2;i++){
		if(s[i]!=s[m/2+i])ans++;
	}
	for(int i=m/2;i<m;i++){
		if(s[i]!=s[i-m/2])ans2++;
	}
	cout<<min(ans,ans2);
}
