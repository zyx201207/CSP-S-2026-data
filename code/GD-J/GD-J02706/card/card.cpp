#include <bits/stdc++.h>
using namespace std;
const int maxn=514,maxm=217;
int n,m,a[maxn],cnt[maxm];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int b[maxn]={0},c[maxm]={0},ptr=1;
		memset(b,0,sizeof b);
		memset(c,0,sizeof c);
		for(int j=i;j<=n;j++){
			if(c[a[j]]==0){
				b[ptr]=a[j];
				c[a[j]]=ptr;
				ptr++;
			}
			else{
				int p=c[a[j]];
				for(int k=p;k<=ptr-1;k++){
					c[b[k]]=0;
					b[k]=0;
				}
				ptr=p;
				b[ptr]=a[j];
				c[a[j]]=ptr;
				ptr++;
			}
		}
		for(int j=1;j<=m;j++){
			if(c[j]!=0){
				cnt[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
