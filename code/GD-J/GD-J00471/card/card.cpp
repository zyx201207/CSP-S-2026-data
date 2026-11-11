#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500007];
ll b[300007];
ll last[300007];
ll cnt[300007];
bool cmp(int x,int y){
	return last[x]<last[y];
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		last[a[i]]=i;
		cnt[a[i]]++;
	}
	for(int i=1;i<=m;i++)
		b[i]=i;
	sort(b+1,b+1+m,cmp);
	for(int i=1;i<=m;i++)
		cnt[a[last[b[i]]+1]]+=cnt[b[i]];
	for(int i=1;i<=m;i++){
		cout<<cnt[i];
		if(i!=m)
			cout<<" ";
	}
	return 0;
}
