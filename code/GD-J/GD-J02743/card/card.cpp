#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],c[500005],d[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>d[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			a[j]=d[j];
			b[a[j]]=0;
		}
		for(int j=i;j<=n;j++){
			b[a[j]]+=1;
			if(b[a[j]]==2){
				for(int k=j-1;k>=1;k--){
					if(a[k]==a[j]){
						b[a[k]]=1;
						a[k]=0;
						break;
					}
					else b[a[k]]=0,a[k]=0;
				}
			}
		}
		for(int j=i;j<=n;j++){
			c[a[j]]+=1;
		    b[a[j]]=0;	
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
