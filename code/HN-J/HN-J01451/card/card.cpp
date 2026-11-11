#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005],t1[300005],t2[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1; j<=m;j++){
			b[j]=0;
		}
		for(int j=1; j<=m;j++){
			t1[j]=0;
		}
		for(int j=i;j<=n;j++){
			b[j]=a[j];
			t1[b[j]]++;
			if(t1[b[j]]==2){
				for(int z=j-1; z>=1; z--){
					if(b[z]==b[j]){
						
						for(int x=z; x<j;x++){
							b[x] = 0;
						}
					}
				}
			}
			
		}for(int j=1; j<=m+1;j++){
			if(b[j]){
				t2[j]++;
			}
		}
	}
	for(int i=1;i<=m+1;i++){
		cout<<t2[i]<<" ";
	}
	return 0;
}
