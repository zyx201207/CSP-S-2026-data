#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],c[300005],nxt[500005],d[500005],e[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(c[a[i]]){
			nxt[c[a[i]]]=i;
			c[a[i]]=i;
		}else{
			c[a[i]]=i;
		}
		b[i]=1;
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		if(nxt[i]!=0){
			int minus=min(i,sum+b[i]);
			b[i]-=minus;
			b[nxt[i]]+=minus;
			
		}
		sum+=b[i];
	}
	for(int i=1;i<=n;i++){
		d[i]=d[i-1]+b[i];
		e[a[i]]+=d[i];
	}
	for(int i=1;i<=m;i++){
		cout<<e[i]<<' ';
	}
	return 0;
}
