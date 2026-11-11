#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005],c[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int ans=0;
		for(int j=i;j<=n;j++){
			for(int k=1;k<=ans;k++){
				if(b[k]==a[j]){
					for(int l=k;l<=ans;l++){
						b[l]=0;
					}
					ans=k-1;
					break;
				}
			}
			b[ans+1]=a[j];
			ans++;
		}
		for(int j=1;j<=m;j++){
			for(int k=1;k<=ans;k++){
				if(b[k]==j){
					++c[j];
					break;
				}
			}
		}
		for(int j=1;j<=ans;j++){
			b[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<c[i]<<" ";
	} 
	return 0;
}
