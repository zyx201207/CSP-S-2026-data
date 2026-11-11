#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m,a[N],f[N],b[N],ans[N],t;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		t=0;
		memset(b,0,sizeof(b));
		memset(f,0,sizeof(f));
		for(int j=i;j<=n;j++){
			int ff=0;
			if(f[a[j]]<=t&&f[a[j]]){
				t=f[a[j]]-1;
			}
			b[++t]=a[j],f[a[j]]=t;
		}
		for(int j=1;j<=t;j++)ans[b[j]]++;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}

