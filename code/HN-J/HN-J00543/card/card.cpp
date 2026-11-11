#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005],c,e[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(e[a[i]]==0){
			e[a[i]]=1;
			c++;
		}
	}
	for(int i=1;i<=m;i++){
		int d=i;
		for(int j=i+1;j<=n;j++){
			for(int k=j-1;k<=i;k--){
				if(a[k]==a[j]){
					d=j;
				}
			}
		}
		for(int j=d;j<=n;j++){
			if(b[a[j]]!=i)b[a[j]]+=1;
		} 
	}                   
	for(int i=1;i<=c;i++){
		cout<<b[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
