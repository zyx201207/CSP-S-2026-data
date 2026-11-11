//CSP-J00396 张轩哲 贵阳市第三中学 
#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int n,m,a[N],b[M];
struct node{
	bool f;
	int w=-1;
}q[M];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		memset(q,0,sizeof(q));
		for(int j=i;j<=n;j++){
			if(!q[a[j]].f){
				q[a[j]].f=1;
				q[a[j]].w=j;
			}else{
				for(int k=q[a[j]].w+1;k<j;k++){
					q[a[k]].f=0;
					q[a[k]].w=-1;
				}
				q[a[j]].w=j;
			}
		}
		for(int j=1;j<=m;j++){
			if(q[j].f){
				b[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	
	return 0;
}
