#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500010],b[500010],c[500010],d[500010];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int s=1;
		for(int j=i;j<=n;j++){
			b[s]=a[j];
			s++;
			c[a[j]]++;
			if(c[a[j]]==2){
				s--;
				c[b[s]]--;
				b[s]=0;
				int l=0;
				while(l==0){
					s--;
					if(b[s]==a[j]){
						l=1;
						s++;
					}else{
						c[b[s]]--;
						b[s]=0;
					}
				}
			}
		}
		for(int i=1;i<=m;i++){
			d[i]+=c[i];
			c[i]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<d[i]<<" ";
	}
	return 0;
}
