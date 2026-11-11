#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[100000005],b[100000005],c[100000005],f[100000005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int d=1;
	for(int i=1;i<=n;i++){
		d=1;
		for(int j=i;j<=n;j++){
			b[d]=a[j];
			for(int k=1;k<j;k++){
				if(b[d]==b[k]){
					for(int s=k+1;s<=j;s++){
						b[s]=0;
					}
				}
			}
			d++;
		}
		for(int k=1;k<=n;k++){
			if(b[k]!=0 &&f[b[k]]==0){
				c[b[k]]++;
				f[b[k]]=1;
			}
		}
		for(int s=1;s<n;s++){
			f[s]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
