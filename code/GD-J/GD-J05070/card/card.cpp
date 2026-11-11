#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[511000],b[511000],cnt[311000];
bool v[511000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			b[j]=a[j];
			int s=a[j];
			for(int k=i;k<=j;k++){
				if(b[k]==s){
					for(int l=k;k<=j-1;j++){
						v[l]=1;
					}
					break;
				}
			}
		}
		for(int k=i;k<=n;k++){
			if(v[k]==0){
				cnt[b[k]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}
