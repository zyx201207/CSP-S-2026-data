#include<bits/stdc++.h>
using namespace std;
string s,p[100005];
long long n,x[100005],ans=0;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int k=1;k<=n;k++){
		cin>>x[k]>>p[k];
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=x[i];j++)
			s+=p[i];
	for(int i=0;i<int(s.size())/2;i++)
		if(s[i]!=s[s.size()-i-1]) ans++;
	cout<<ans;
	return 0;
}
