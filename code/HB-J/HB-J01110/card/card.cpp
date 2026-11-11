#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500005],b[300005],f[500005],ans[300005],n,m,z;
//b:tong yong yu cun fang a[i]xia biao
//f:dang qian zhuang tai
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int p=1;p<=n;p++){
		for(int i=p;i<=n;i++){
			ll x=a[i];
			if(b[x]>0){
				ll last=z;
				for(int j=b[x]+1;j<=last;j++) b[f[j]]=0,f[j]=0,z--;
			}
			else {
				z++;
				b[x]=z;
				f[z]=x;
			}
		}
		for(int i=1;i<=m;i++) if(b[i]) ans[i]++;
		memset(b,0,sizeof(b));
		memset(f,0,sizeof(f));
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
