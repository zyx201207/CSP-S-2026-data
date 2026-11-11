#include<bits/stdc++.h>
using namespace std;
int a[200009],b[200090],c[200009];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int p=1;
		b[1]=a[i];
		for(int j=i+1;j<=n;j++){
			int f=0;
			for(int k=p;k>=1;k--){
				if(b[k]==a[j]){
					f=1;
					break;
				}
			}
			if(f==0) b[++p]=a[j];
			else{
				int q=p;
				for(int k=q;k>=1;k--){
					if(b[k]!=a[j]){
						b[k]=0;
						p--;
					}
					else break;
				}
			}
		}
		for(int j=1;j<=p;j++){
			c[b[j]]++;
		}
		for(int j=1;j<=7000;j++) b[j]=0;
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
}
