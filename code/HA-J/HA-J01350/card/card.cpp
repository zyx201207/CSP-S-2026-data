#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int a[N],b[N],c[N],d[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int now=1;
		for(int j=1;j<=m;j++)c[j]=-1;
		for(int j=i;j<=n;j++){
			if(c[a[j]]==-1){
				c[a[j]]=now;
				b[now++]=a[j];
			}else{
				int v;
				for(int z=1;z<now;z++)if(b[z]==a[j])v=z;
				for(int z=v+1;z<now;z++)c[a[j]]=-1;
				now=v+1;
		 }
		}
		for(int j=1;j<now;j++)d[b[j]]++;
	}
	
	for(int i=1;i<=m;i++)cout<<d[i]<<' ';
	return 0;
}

