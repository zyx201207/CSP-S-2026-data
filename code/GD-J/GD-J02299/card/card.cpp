#include<bits/stdc++.h>
using namespace std;

int n,m,a[500005],b[300005],j;
bool d[300005];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int k=1;k<=n;k++){
		j=k-1;
		for(int i=1;i<=m+1;i++){
			d[i]=0;
		}
		for(int i=k;i<=n;i++){
			if(!d[a[i]]){
				d[a[i]]=1;
				j++;
			}
			else{
				int p=j;
				while(a[p]!=a[i]){
					d[a[p]]=0;
					p--;
				}
			}
		}
		for(int i=1;i<=m;i++){
			if(d[i]){
				b[i]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";	
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
