#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a,len=0,ans=0;
string c,s="";
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a>>c;
		len+=a;
		for(int j=1;j<=n;j++) s+=c;
	}
	for(int i=0;i<(len+1LL)/2;i++)
		if(s[i]!=s[n-i+1]) ans++;
	cout<<ans;
	return 0;
}
