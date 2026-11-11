#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
int ans;
int a[300005];
int table[300005];
int cnt[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			table[j]=a[j];
			for(int k=i;k<j;k++){
				if(table[k]==table[j]){
					for(int I=j-1;I>=k;I--){
						table[I]=0;
					}
				}
			}
			
		}
		for(int j=i;j<=n;j++){
			cnt[table[j]]++;
			table[j]=0;
		}
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<' ';
	return 0;
}
