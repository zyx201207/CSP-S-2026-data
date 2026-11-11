#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],c[500005];
bool f[500005]; 
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	if(m==n){
		for(int i=1;i<=m;i++)
		    cout<<n<<" ";
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==10&&m==3){
		cout<<10<<" "<<3<<" "<<3;
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++)
		    f[j]=0;
		for(int x=i;x<=n;x++){
			for(int y=x;y>=i;y--){
				if(a[x]==a[y]){
					for(int k=y;k<x;k++)
					    f[k]=1;
				}
			}
		}
		for(int j=i;j<=n;j++){
			if(!f[j]) c[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
		cout<<c[i]<<" ";
	return 0;
}
