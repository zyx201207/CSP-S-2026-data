#include<bits/stdc++.h>
using namespace std;
long long n,pp,l,ans,p,q;
string s;
char k;
int main() {
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>pp>>k;
		for(int i=1;i<=pp;i++){
			s+=k;
		}
	}
	int l=s.size();
	for(int i=0;i<l/2;i++){
		if(s[i]!=s[l-i+1])ans++;
	}
	cout<<ans;
}
