#include<bits/stdc++.h>
using namespace std;
int a[500010],c[500010],d[500010];
struct node{
	int x;
	bool f;
}b[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int cnt=0;
		memset(c,0,sizeof(c));
		memset(b,0,sizeof(b));
		for(int j=i;j<=n;j++){
			if(!b[a[j]].f){
				b[a[j]].f=1;
				b[a[j]].x=++cnt;
				c[cnt]=a[j];
			}
			else{
				for(int k=b[a[j]].x+1;k<=cnt;k++){
					b[c[k]].f=0;
					b[c[k]].x=0;
					c[k]=0;
				}
				cnt=b[a[j]].x;
			}
		}
		for(int i=1;i<=m;i++){
			if(b[i].f) d[i]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<d[i]<<" ";
	return 0;
}

