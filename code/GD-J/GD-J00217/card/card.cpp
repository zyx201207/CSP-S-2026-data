#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005],du[300005],p[300005],q[300005],l=1,r;
bool v[300005];
void bfs(){
	for(int i=1;i<=m;i++){
		if(du[i]==0)
			r++,q[r]=i;
	}
	while(l<=r){
		int u=q[l];
		l++;
		if(p[u]!=0){
			b[p[u]]+=b[u],du[p[u]]--;
			if(du[p[u]]==0)	r++,q[r]=p[u];
		}	
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		b[a[i]]++;
	}
	for(int i=n;i>0;i--){
		if(v[a[i]]==1)	continue;
		v[a[i]]=1;
		if(i!=n)	p[a[i]]=a[i+1],du[a[i+1]]++;
	}
	bfs();
	for(int i=1;i<=m;i++)
		cout<<b[i]<<" ";
	return 0;
}
