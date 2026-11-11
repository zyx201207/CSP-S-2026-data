#include<bits/stdc++.h>
using namespace std;
int n,m;
int arr[500005],ans[300005];
int table[500005],Index;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	for(int i=0;i<n;i++){
		Index=0;
		for(int j=i;j<n;j++){
			for(int k=0;k<Index;k++){
				if(table[k]==arr[j]){
					Index=k;
					break;
				}
			}
			table[Index]=arr[j];
			Index++;
		}
		for(int j=0;j<Index;j++){
			ans[table[j]-1]++;
		}
	}
	for(int i=0;i<m;i++){
		printf("%d ",ans[i]);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
