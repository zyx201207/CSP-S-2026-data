#include<bits/stdc++.h>

using namespace std;

int b[500010],c[300010];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[500010];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int s=0;s<n;s++){
		for(int i=s;i<n;i++){
			for(int j=i-1;j>=0;j--){
				if(b[j]==a[i]){
					for(int k=j;k<n;k++){
						b[k]=0;
					}
				}
			}
			b[i]=a[i];
		}
		for(int i=s;i<n;i++){
			c[b[i]]++;
		}
		int b[500010]={};
	}

	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
