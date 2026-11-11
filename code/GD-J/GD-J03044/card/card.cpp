#include<bits/stdc++.h>

using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[500010],b[300010],c[300010],d[500010];//a存数据，b排除，c存sum
	cin>>n>>m; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int w=i;w<=n;w++){ 
			c[a[w]]++;//a[w]指第a[i]个代表数 
			if(b[a[w]]==0){
				b[a[w]]=1;
			}
			else{
				c[a[w]]--;
				int q=w-1;
				int j=a[q];
				while(j!=a[w]){
					if(d[j]==0){
						c[j]--;
						d[j]=1;
					}
					q-=1;
					j=a[q];
				}
				for(int t=1;t<=m;t++){
					if(c[i]==0){
						b[i]=0;
					}
				}
			}
		}
		for(int i=1;i<=m;i++){
			if(b[i]!=0) b[i]=0;
		}
		for(int i=1;i<=n;i++){
			d[i]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
