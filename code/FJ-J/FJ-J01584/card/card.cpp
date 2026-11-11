#include <bits/stdc++.h>
using namespace std;
const int N=2e5+1;
int n,m;
int a[N];
int tail=0,q[N];
bool v[N];
int last[N];
int ans[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(!v[a[j]]) q[++tail]=a[j],last[a[j]]=tail,v[a[j]]=1;
			else{
				for(int k=last[a[j]]+1;k<=tail;k++) v[q[k]]=0;
				tail=last[a[j]];
			}
		}
		for(int j=1;j<=tail;j++) ans[q[j]]++;
		memset(v,0,sizeof(v));
		memset(q,0,sizeof(q));
		memset(last,0,sizeof(last));
		tail=0;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}

