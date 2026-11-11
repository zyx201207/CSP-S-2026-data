#include<bits/stdc++.h>
using namespace std;
int a[200005];
int c[301];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		
		for(int j=i;j<=n;j++){
			c[a[j]]++;
			for(int k=j;k>=i;k--){
				
				if(a[j]==a[k]){
					for(int g=k;g<=j-1;g++){
						c[g]--;
					}
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
