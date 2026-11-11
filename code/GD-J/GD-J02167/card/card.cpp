#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,m;
int a[N],b[N],c[N],d[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		int t=0;
		for(int j=i;j<=n;j++){
			int k=a[j];
			if(b[k]!=0){
				for(int o=1;o<=m;o++){
					if(o==k) continue;
					if(b[o]<=t&&b[o]>=b[k]) b[o]=0;
				}
				t=b[k];
			}
			else{
				c[++t]=k;
				b[k]=t;
			}
		}
		for(int j=1;j<=t;j++){
			d[c[j]]++;
		}
	} 
	for(int i=1;i<=m;i++) cout<<d[i]<<" ";
	return 0;
}

