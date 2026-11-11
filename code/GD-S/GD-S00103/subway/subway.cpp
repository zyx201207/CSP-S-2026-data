#include<bits/stdc++.h>
using namespace std;
int a[100005][505][2],c,n,m,d,q,l[100005][2],lo[505],t,ma[505][100005];
void se(){
	for(int i=1;1<=n;i++){
		if(a[1][i][0]!=0)
	}
}
int main(){
	//freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		scanf("%d",&a[i][0][0]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&lo[i]);
		for(int j=1;i<=lo[i];i++){
			scanf("%d",&t);
			scanf("%d",&a[t][i][1]);
			a[t][i][0]=j;
			ma[i][j]=t;
		}
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&l[i][0]);
		scanf("%d",&l[i][1]);
	}
	
	//fclose(stdin);
	//fclose(stdout);
} 
