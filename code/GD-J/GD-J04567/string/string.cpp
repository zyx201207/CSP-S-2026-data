#include<bits/stdc++.h>
using namespace std;
string s;
char c[2000005];
long long n,i,j,a[2000005],ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[i]>>c[i];
		for(j=0;j<a[i];j++)s+=c[i];
	}
	for(i=0,j=s.size()-1;i<=j;i++,j--)
		if(s[i]!=s[j])ans++;
	cout<<ans<<'\n';
	return 0;
}
