#include<bits/stdc++.h>
using namespace std;
int a[500005],sum[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=n;
	}
	int f=1;
	while(f<=n){
		for(int i=f;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[i]==a[j]){
					for(int t=i;t<j;t++){
						sum[t]--; 
					} 
					i=j;
				}
			}
		}
		f++;
	}
	for(int i=1;i<=n;i++){
		cout<<sum[i]<<' ';
	}
	return 0;
} 
