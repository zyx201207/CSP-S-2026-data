#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m;
ll a[500005];
ll b[500005];
ll s[500005];
bool vis[500005];
int main(){
	freopen("card.in","r",stdin);
	freoprn("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		memset(s,0,sizeof(s));
		memset(vis,false,sizeof(vis));
		int k=0;
		for(int j=i;j<=n;j++){
			if(k==0){
				k++;
				s[k]=a[j];
			}
			else{
				int len=1;
				while(len<=k&&s[len]!=a[j]){
					len++;
				}
				k=len-1;
				k++;
				s[k]=a[j];
			}
		}
		for(int j=1;j<=k;j++){
			if(vis[s[j]]==false){
				b[s[j]]++;
				vis[s[j]]=true;
			}
		}
	}
	for(int i=1;i<=m;i++){
		if(b[i]!=0){
			cout<<b[i]<<" ";
		}
	}
	return 0;
} 
