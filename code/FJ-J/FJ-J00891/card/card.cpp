#include<bits/stdc++.h>
using namespace std;
int a[500005];
int b[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int l[500005],k=0;
		for(int j=i;j<=n;j++){
			k++;
			for(int o=1;o<=k-1;o++){
				if(l[o]==l[k]){
					k=o+1;
					break;
				}
			}
			l[k]=1;
			
		}
	}
	for(int i=1;i<=m;i++){
		cout<<0<<" ";
	}
	return 0;
} 
