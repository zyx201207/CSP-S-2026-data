#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],num[300005];
ll check[300005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(!check[a[j]]){
				check[a[j]]++;
			}
			else{
				for(int k=j-1;k>=1;k--){
					if(a[k]==a[j]){
						break;
					}
					check[a[k]]=0;
				}
			}
		}
		for(int j=1;j<=m;j++){
			if(check[j]!=0)num[j]++;
			check[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<num[i]<<' ';
	}
	cout<<"\n";
	return 0;
} 
