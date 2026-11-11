#include<bits/stdc++.h>
using namespace std;
int cnt[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int k=0;k<n;k++){
		int ds[n],dsl=0;
		for(int i=0;i<n-k;i++){
			for(int j=0;j<dsl;j++){
				if(ds[j]==a[i+k]){
					dsl=j;
					break;
				}
			}
			ds[dsl]=a[i+k];
			dsl++;
		}
		for(int i=0;i<dsl;i++){
			cnt[ds[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
} 
