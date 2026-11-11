#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int b[500005];
int c[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		int k=0;
		for(int j=i;j<n;j++){
			for(int o=0;o<k;o++){
				if(b[o]==a[j]){
					k=o;
				}
			}
			b[k]=a[j];
			k++;
		}
		for(int j=0;j<k;j++){
			c[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
}
