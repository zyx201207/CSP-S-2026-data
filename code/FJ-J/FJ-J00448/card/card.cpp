#include<bits/stdc++.h>
using namespace std;
int n,m,a[(int)5e5+10],t[(int)5e5+10],b[(int)5e5+10];
int find(int x){
	for(int i=1;i<=n;i++)
		if(t[i]==x)return i;
	return -1;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++){
		int e=0;
		for(int i=1;i<=n;i++)t[i]=0;
		for(int j=i;j<=n;j++){
			if(find(a[j])==-1)t[++e]=a[j];
			else while(e>find(a[j]))t[e--]=0;
		}
		for(int j=1;t[j]!=0;j++)b[j]++;
	}
	for(int i=1;i<=m;i++)
		printf("%d ",b[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

