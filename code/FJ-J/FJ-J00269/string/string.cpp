#include <bits/stdc++.h>
using namespace std;
const int N=1e6;
int len[N];
string c[N];
int n,l=0,ans=0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie();cout.tie();
	cin>>n;
	memset(len,0,sizeof(len));
	for(int i=1;i<=n;i++){
		int x;cin>>x>>c[i];
		len[i]=l+x;
		l+=x;
	}
	for(int i=1;i<=l/2;i++){
		int ps=i,pe=l+1-i;
		string s,e;
		for(int j=1;j<=n;j++)
			if(ps>len[j-1]&&ps<=len[j]) s=c[j];
		for(int j=1;j<=n;j++)
			if(pe>len[j-1]&&pe<=len[j]) e=c[j];
		if(s!=e) ans++;
	}
	cout<<ans;
	return 0;
}
