#include<bits/stdc++.h>
using namespace std;
int n,m,a[514151],b[514514];
bool c[514514];int d[314514],e[314514];
int main(){
	freopen("card.in","r",stdin);freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>m;for(int i=1;i<=n;i++)cin>>a[i];
    for(int o=1;o<=n;o++){
		memset(b,0,sizeof(b));int y=0;for(int j=o;j<=n;j++)b[++y]=a[j];
		memset(c,0,sizeof(c));
		for(int i=1;i<=y;i++){
			if(!d[b[i]])d[b[i]]=i;
			else{
				if(!c[d[b[i]]]){
					for(int j=d[b[i]];j<i;j++){
						c[j]=true;
					}
				}d[b[i]]=i;
			}
		}for(int i=1;i<=y;i++){
			if(!c[i])e[b[i]]++;
		}
	}for(int i=1;i<=m;i++)cout<<e[i]<<' ';
	return 0;
}
