#include<bits/stdc++.h>
using namespace std;
long long n,m,f;
long long a[1000000];
long long b[1000000];
long long c[1000000],vis[1000000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=0;i<n;i++){
		cin>>a[i];
	}
	for(long long i=0;i<n;i++){
		for(long long j=i;j<n;j++){
			if(vis[a[j]]==0){
				b[j]=a[j];
				vis[a[j]]++;
			}
			else{
				for(long long k=0;k<n;k++){
					if(b[k]==a[j]){
						f=k;
						break;
					}
				}
				for(long long k=f+1;k<j;k++){
					vis[b[k]]=0;
					b[k]=0;
				}
			}
		}
		for(long long j=1;j<=m;j++){
			c[j]+=vis[j];
			vis[j]=0;
		}
		for(long long j=0;j<n;j++){
			b[j]=0;
		}
	}
	for(long long i=1;i<=m;i++){
		cout<<c[i]<<" ";
	}
	return 0;
} 

