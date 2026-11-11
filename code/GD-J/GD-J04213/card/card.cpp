#include <bits/stdc++.h>
using namespace std;
int m,n,a[100005],b[100005],c[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int k=0;
	for(int i=1;i<=n;i++){
		k=0;
		for(int j=i;j<=n;j++){
			if(b[a[j]]==0){
				b[a[j]]=++k;
			}
			else k=b[a[j]];
		}
		for(int x=1;x<=m;x++){
			if(b[x]!=0 && k>=b[x]) c[x]++;
			b[x]=0;
		}
	}
	for(int i=1;i<=m;i++) cout<<c[i]<<" ";
	
	return 0;
}
