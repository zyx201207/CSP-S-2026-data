#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500009],son[500009],b[300009],mn[400009],cnt=1;
int find(int x){
	if(son[x]==0)return x;
	son[x]=find(son[x]);
	return son[x];
}
int main(){
	freopen("card.in","r",stdin);	
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(b[a[i]]!=0){
			son[b[a[i]]]=i;
		}
		b[a[i]]=i;
	}
	memset(b,0,(m+3)*sizeof(int));
	for(int i=1;i<=n;i++){
		if(b[a[i]]==0&&son[i]!=0){
			b[a[i]]=1;
			son[i]=find(son[i]);
		}
	}
	memset(b,0,(m+3)*sizeof(int));
	for(int k=1;k<=n;k++){
		cnt=1;
		for(int i=k;i<=n;i++){
			if(son[i]==0){
				mn[cnt++]=a[i];
			}else{
				while(son[i]!=i&&son[i]!=0){
					i=son[i];
				}
				mn[cnt++]=a[i];
			}
		}
		for(int i=1;i<cnt;i++){
			b[mn[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",b[i]);
	}

	fclose(stdin);
	fclose(stdout);
	return 0;
}
