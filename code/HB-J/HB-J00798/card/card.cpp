#include<bits/stdc++.h>
using namespace std;
int a[2010],b[2010],d[2010];
bool r[2010];
struct node{
	bool f=0;
	int wei;
}c[2010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,now_=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
//	for(int i=1;i<=m;i++) cout<<1<<" ";
	for(int i=1;i<=n;i++){
		memset(r,0,sizeof(r));
		memset(d,0,sizeof(d));
		for(int j=i;j<=n;j++){
			if(c[a[j]].f){
				for(int k=c[a[j]].wei;k<=now_;k++){
					d[k]=0;
				}
				now_=c[a[j]].wei;
			}
			else now_++;
			d[now_]=a[j];
			c[a[j]].f=1;
			c[a[j]].wei=now_;
		}
		for(int j=1;j<=now_;j++){
			if(r[d[j]]==0){
				b[d[j]]++;
				r[d[j]]=1;
			}
		}
		for(int j=1;j<=m;j++){
			c[a[j]].f=0;
			c[a[j]].wei=0;
		}
	}
	for(int i=1;i<=m;i++) cout<<b[i]<<" ";
	return 0;
}
