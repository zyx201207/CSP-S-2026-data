#include<bits/stdc++.h>
using namespace std;
int a[1000],cnt[1000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int b=1;b<=m;b++){
		int f[1000],k=0;
		for(int i=b;i<=n;i++){
			for(int z=1;z<=k;z++){
				if(a[i]==f[z]){
					for(int r=1;r<=k;r++){
						f[r]=0;
					}
					k=1;
					f[k]=a[i];
				}
				else{
					k++;
					f[k]=a[i];
				}
			}
			for(int i=1;i<=k;i++){
				cnt[f[i]]++;
			}
			
		}
	}
	for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";
	
	return 0;
}
