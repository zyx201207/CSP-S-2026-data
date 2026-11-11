#include<iostream>
#include<cstdio>
using namespace std;
int a[300010],b[300010],sum[50010];
int n,m;
int main(){
	freopen("card.in","r",stdin); 
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int tot=0,c[500010];
		for(int j=i;j<=n;j++){
			b[++tot]=a[j];
			c[a[j]]++;
			if(c[a[j]]==2){
				for(int k=1;k<=tot;k++){
					if(b[k]==b[tot]){
					tot=k;
					c[b[j]]=0;
					break;	
					} 
				}
			}
		}
		for(int f=1;f<=tot;f++){
			sum[b[f]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<sum[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
