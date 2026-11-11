#include<bits\stdc++.h>
using namespace std;
int n,m,a[500005],b[300005],c[500005],d[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			c[j]=a[j];
		}
		for(int j=i;j<=n;j++){
			if(b[a[j]]==0) b[a[j]]=j;
			else{
				for(int k=b[a[j]];k<=j-1;k++){
					b[a[k]]=0;c[k]=0;
				} 
				b[a[j]]=j;
			}
		}
		for(int j=i;j<=n;j++){
			if(c[j]!=0) d[c[j]]++;
		}
		for(int j=1;j<=m;j++){
			b[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<d[i]<<" ";
	}
	return 0;
}
