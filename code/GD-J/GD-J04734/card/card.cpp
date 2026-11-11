#include<bits/stdc++.h>
using namespace std;
const int N=5e5+11;
int a[N],ans[N],n,m,y[N],c[N];
bool v[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		y[a[i]]=i,c[i]=1;
	}
	for(int i=1;i<=n;i++)ans[a[i]]+=c[i],c[y[a[i]]+1]+=c[i];
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
