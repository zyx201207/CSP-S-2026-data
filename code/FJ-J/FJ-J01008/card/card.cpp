#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005],num[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n-i;j++){
			for(int k=1;k<=j;k++){
				if(a[j+i]==b[k]){
					for(int z=k;z<=j;z++){
						b[z]=0;
					}
				}
			}
			b[j+1]=a[j+i];
		}
		for(int j=1;j<=n-i+1;j++){
			num[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<num[i]<<" ";
	}
	return 0;
}

