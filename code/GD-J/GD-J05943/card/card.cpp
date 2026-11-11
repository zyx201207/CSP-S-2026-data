#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],b[200005],c[300005];
int find1(int x,int y,int tar){
	for(int i=x;i<=y;i++){
		if(b[i]==tar)return i;
	}
	return -1;
}
int find2(int x,int y,int tar){
	int sum=0;
	for(int i=x;i<=y;i++){
		if(b[i]==tar)sum++;
	}
	return sum;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		memset(b,0,sizeof(b));
		int l=0;
		for(int j=i;j<=n;j++){
			int s=find1(1,l,a[j]);
			if(s!=-1&&s<=l){
				for(int k=s;k<=l;k++){
					b[k]=0;
				}
				b[s]=a[i];
			}
			else b[++l]=a[j];
		}
		for(int k=1;k<=m;k++){
			c[k]=find2(1,l,k);
		}
	}
	for(int k=1;k<=m;k++){
		printf("%d ",c[k]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
