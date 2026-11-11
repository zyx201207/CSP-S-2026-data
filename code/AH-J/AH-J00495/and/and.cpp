#include <bits/stdc++.h>
using namespace std;
#define F std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
typedef unsigned long long ull;
ll n,m,h[200005],f[200005],i,j,k,N;
int main(void){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	F;
	string s[200005];
	map<int,int,greater<int> > mp;
	cin>>n>>m;
	for(i=1;i<=n;++i)cin>>h[i];
	sort(h+1,h+n+1,greater<int>());
	for(i=1;i<=n;++i){
		for(j=h[i];j;j>>=1)s[i].push_back((j&1)+'0');
		for(j=0;j<s[i].size();++j)
			if((s[i][j]-'0'))mp[j]+=1;
	}
	N=n,k=0;
	for(auto it:mp){
		if(it.second<m)continue;
		for(i=1,j=0;i<=n;++i)j+=(!f[i]&&(s[i].size()>it.first&&s[i][it.first]=='1'));
		if(j<m)continue;
		for(i=1;i<=n&&N>=m;++i){
			if(f[i])continue;
			if(s[i].size()<=it.first||s[i][it.first]=='0')f[i]=1,N--;
		}
		if(N>=m)k+=1<<(it.first);
		else break;
	}
	cout<<k<<"\n";
	return 0;
}
