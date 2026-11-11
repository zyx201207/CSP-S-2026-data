#include<bits/stdc++.h>
using namespace std;
const int MAXN=500005;
const int MAXM=300005;
int n,m,l=0;
int a[MAXN],len[MAXN];
int xb[MAXM];
int qb[MAXM];
struct node{
	int s,b;
}sz[MAXM];
void sans(int kk){
	for(int k=kk;k<l;k++){
		len[k]=0;
		xb[a[k]]=0;
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<n;i++){
		memset(len,0,sizeof(len));
		memset(xb,0,sizeof(xb));
		l=0;
		for(int j=i;j<n;j++){
			if(xb[a[j]]==0){
				len[l]=a[j];
				xb[a[j]]=1;
				sz[a[j]].b=j;
			}
			else{
				sans(sz[a[j]].b);
				l=sz[a[j]].b;
				len[l]=a[j];
				xb[a[j]]=1;
			}
			l++;
		}
		for(int j=1;j<=m;j++){
			qb[j]+=xb[j];
		}
	}
	for(int i=1;i<=m;i++){
		if(i!=m)
		    printf("%d ",qb[i]);
		else
		    printf("%d",qb[i]);
	}
	return 0;
}
