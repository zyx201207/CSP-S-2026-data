#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500001],b[300001],c[300001],x[300001],n,m,s,t;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int v=1;v<=n;v++){
		t=0;
		memset(b,0,sizeof(b));
		for(int i=v;i<=n;i++){
			if(b[a[i]]==0)b[a[i]]=++t,x[a[i]]++,c[t]=a[i];
			else{
				for(int j=b[a[i]]+1;j<=t;j++)b[c[j]]=0,x[c[j]]--;
				t=b[a[i]];
			}
		}
	}
	for(int i=1;i<=m;i++)cout<<x[i]<<' ';
	return 0;
}
