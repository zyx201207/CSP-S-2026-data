#include<bits/stdc++.h>
using namespace std;
int a[500005],c[500005],d[300005];
struct node{
	int x;
	int y;
};
node b[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int k=0;k<=m;k++) b[k].x=b[k].y=0;
		for(int k=1;k<=n;k++) c[k]=0;
		for(int j=i;j<=n;j++){
			if(b[a[j]].x==1){
				for(int k=b[a[j]].y;k<j;k++){
					b[c[k]].x=0;
					b[c[k]].y=0;
					c[k]=0;
				}
			}
			b[a[j]].x=1;
			b[a[j]].y=j;
			c[j]=a[j];
		}
		for(int j=i;j<=n;j++){
			if(c[j]!=0) d[c[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<d[i]<<" ";
	}
	return 0;
}
