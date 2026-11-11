#include<bits/stdc++.h>
using namespace std;
int c,m;
int main(){
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	cin>>c>>m;
	for(int i=1;i<=m;i++){
		long long a[100005],n,l;
		cin>>n>>l;
		for(int j=1;j<=n;j++){
			cin>>a[j];
		}
		long long sum=0;
		for(int u=1;u<=n;u++){
			for(int k=u+1;k<=n;k++){
				if(a[k]==l*2+a[u]-1&&k-u>1){
					sum++;
				}
			}
		}
		cout<<sum;
	}
	return 0;
} 
