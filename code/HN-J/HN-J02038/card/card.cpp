#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	int a[n],b[n],c[m];
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<n;j++){
			int y=0;
			for(int v=0;v<n;v++){
				if(a[j]==b[v]){
					y=v;
					break;
				}
			}
			if(y==0){
				b[j]=a[j];
			}
			else{
				for(int v=y+1;v<=n;v++){
					b[v]=0;
				} 
			}
		}
		for(int j=0;j<m;j++){
			c[b[j]]++;
		}
		for(int j=0;j<m;j++){
			cout<<c[j]<<" ";
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
