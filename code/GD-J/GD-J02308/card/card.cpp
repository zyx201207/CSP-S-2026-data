#include<bits/stdc++.h>
using namespace std;
int a[500005];
int pp[300005];
int jp[500005][32];
int la[500005];
int an[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	memset(jp,127,sizeof(jp));
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		jp[pp[a[i]]][0]=i;
		pp[a[i]]=i;
	}
	for(int i=n;i>0;i--){
		for(int j=1;j<22;j++){
			if(jp[i][j-1]>n){
				break;
			}
			jp[i][j]=jp[jp[i][j-1]][j-1];
		}
	}
	for(int i=1;i<=n;i++){
		int t=i;
		for(;t<=n;t++){
			for(int j=21;j>=0;j--){
				if(jp[t][j]<=n){
					t=jp[t][j];
				}
			}
			la[t]++;
		}
	}
	for(int i=1;i<=n;i++){
		an[a[i]]+=la[i];
	}
	for(int i=1;i<=m;i++){
		printf("%d ",an[i]);
	}
	return 0;
}
