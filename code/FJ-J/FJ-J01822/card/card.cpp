#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[1123456];
long long nn[1123456];//当前桌上的牌 
map<long long,long long> t;
long long nni;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			bool ok=1;
			for(int k=1;k<=nni;k++){
				if(nn[k]==a[j]){
					nni=k;
					nn[nni]=a[j];
					ok=0;
					break;
				}
			}
			if(ok){
				nn[++nni]=a[j];
			}
		}
		for(int i=1;i<=nni;i++){
			t[nn[i]]++;
		}
		nni=0;
	}
	for(int i=1;i<=m;i++){
		cout<<t[i]<<" ";
	}
	return 0;
}/*
10 3
3 1 2 1 3 2 3 1 2 1

*/
