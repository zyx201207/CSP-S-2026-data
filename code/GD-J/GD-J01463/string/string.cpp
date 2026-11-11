#include<bits/stdc++.h>
using namespace std;
int n,a[200005];
char c[200005];
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	s='1';
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=a[i];j++){
			s+=c[i];
		}
	}
	long long ans=0;
	long long len=s.size();
	for(int i=1;i<=(len+1)>>1;i++){
		if(s[i]!=s[len-i])ans++;
	}
	cout<<ans;
	
	return 0;
}
