#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long z[500005];
long long l[500005];
long long ans[500005];
bool b[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		long long cnt=0;
		for(int j=i;j<=n;j++){
			if(!l[a[j]]){
				l[a[j]]=++cnt;
				z[cnt]=a[j];
			}
			else{
				long long cntt=cnt;
				cnt=l[a[j]];
				for(int k=cntt;z[k]!=a[j];k--){
					l[z[k]]=0;
				}
			}
		}
		for(int j=1;j<=cnt;j++){
			ans[z[j]]++;
		}
		for(int j=1;j<=m;j++){
			l[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
