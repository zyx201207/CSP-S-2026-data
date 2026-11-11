#include <bits/stdc++.h>
using namespace std;
int n,m,a[50010],vis[500010],s[500010],b[500010];bool pf=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1; i<=n; i++){
		cin>>a[i];
		if(a[i]>a[i+1]){
			pf=1;
		}
	}
	if(pf==1){
		for(int i=1; i<=n; i++){
		for(int j=0; j<=n; j++){
			vis[j]=-1;
			b[i]=0;
		}
		int cnt=0,l=i,r=i-1;
		for(int j=i; j<=n; j++){
			int z=-1;
			for(int k=l; k<=r; k++){
				if(b[k]==a[j]){
					z=k;
					for(int i=r; i>k; i--){
						b[i]=-1;
					}
					r=k;
					break;
				}
			}
			if(z==-1){
				b[++r]=a[j];
			}
		}
		for(int j=l; j<=r; j++){
			s[b[j]]++;
		}
	}
	for(int i=1; i<=m; i++){
		cout<<s[i]<<" ";
	}
	}
	else{
		for(int i=1; i<=n; i++){
			for(int j=i; j<=n; j++){
				if(a[j]!=a[j-1]){
					s[a[j]]++;
				}
			}
		}
		for(int i=1; i<=m; i++){
			cout<<s[i]<<" "; 
		}
	}
	return 0;
}
