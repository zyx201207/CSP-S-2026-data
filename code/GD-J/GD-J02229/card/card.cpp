#include<bits/stdc++.h>
using namespace std;
long long c[30001]={0};
long long n,m,b[30001];
long long a[30001],e[30001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(long long i=1;i<=n;i++){
		e[30001]={0};
		for(long long j=i;j<=n;j++){
			e[a[j]]=1;
			for(long long c=j;c<=n;c++){
				if(a[j]==a[c]){
					long long d=c;
					while(j<d){
						e[a[d]]=0;
						d--;
					}
				}
			}
		}
		for(int z=1;z<=n;z++){
			if(e[z]==1){
				e[z]=0;
				b[z]++;	
			}
		}
	}
	for(int i=1;i<=m;i++) cout<<b[i]<<" ";
	return 0;
}
