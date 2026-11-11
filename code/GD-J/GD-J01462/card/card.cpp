#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans[500005],q[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int z=1;
		for(int j=i;j<=n;j++){
			
			for(int l=1;l<=z;l++){
				if(q[l]==a[j]){
					int s;
					for(s=l;s<=z;s++){
						q[s]=0;
					}
					z=s-1;
					break;
				}
			}
			q[z]=a[j];
			z++;
		}
		for(int j=1;j<z;j++){
			ans[q[j]]++;
			q[j]==0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
} 
