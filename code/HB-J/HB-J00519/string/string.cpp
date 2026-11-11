#include<bits/stdc++.h>
#define ll long long
using namespace std;
//ten year oi one groud null no open long long meet grandfather
int z[3000005];
int n,u,ans,nn;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		int x;
		char y;
		int m;
		cin>>x>>y;
		nn+=x;
		m=y-'a'+1;
		for(int j=1;j<=x;j++){
			z[j+u]=m;
		}
		u+=x;
	}
	for(int i=1;i<=nn/2;i++){
		if(z[i]!=z[nn-i+1])ans++;
	}
	cout<<ans;
	return 0;
}
