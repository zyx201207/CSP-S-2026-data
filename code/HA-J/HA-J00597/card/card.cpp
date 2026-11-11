#include<bits/stdc++.h>
using namespace std;
int n,m,c[300005],k[300005],w[500005],a[500005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(w,0,sizeof(w));
		memset(k,0,sizeof(k));int len=0;
		for(int j=i;j<=n;j++){
			if(k[a[j]]==0){
				len++;
				k[a[j]]=len;
				w[len]=a[j];
			}
			else{
				int p=0;
				for(int x=k[a[j]];x<=len;x++){
					w[x]=0;p++;k[w[x]]=0;
				}
				len-=p;len++;
				k[a[j]]=len;
				w[len]=a[j];	
			}
		}
		for(int j=1;j<=len;j++){
			c[w[j]]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<c[i]<<' ';
	return 0;
}

