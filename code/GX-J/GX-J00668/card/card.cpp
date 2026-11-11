#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[n+1]={},sum[m+1]={};
	for(int i=1;i<=n;i++) cin >> a[i];
	for(int i=1;i<n;i++){
		bool fl[m+1]={};
		for(int j=i;j<=n;j++){
			if(!fl[a[j]]) fl[a[j]]=true;
			else{
				for(int z=j-1;a[z]!=a[j];z--){
					fl[a[z]]=false;
				}
			}
		}
		for(int j=1;j<=m;j++){
			if(fl[j]) sum[j]++;
		}
	}
	sum[a[n]]++;
	for(int i=1;i<=m;i++){
		cout << sum[i] << ' ';
	}
	return 0;
}
