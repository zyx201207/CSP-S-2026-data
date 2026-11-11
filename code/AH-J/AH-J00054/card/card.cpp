#include<bits/stdc++.h>
using namespace std;
long long n,m,c[500005],a[500005],np[200005];
map<long long,long long> mp;
void f(long long ip,long long tzy){
	np[a[ip]]=np[a[ip]]+tzy;
	if(mp[a[ip]]==n)return;
	c[mp[a[ip]]+1]=c[mp[a[ip]]+1]+tzy;
	return;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		c[i]=1;
		mp[a[i]]=i;
	}
	for(long long i=1;i<=n;i++)f(i,c[i]);
	for(long long i=1;i<=m;i++)cout<<np[i]<<" ";
	return 0;
}
