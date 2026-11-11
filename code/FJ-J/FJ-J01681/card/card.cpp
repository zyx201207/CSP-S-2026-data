#include<bits/stdc++.h>
using namespace std;
bool f=1;
long long n,m;
long long a[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]){
			f=0;
		}
	}
	if(f==1){
		for(long long i=1;i<=n;i++){
			if(a[i]!=a[i+1]){
				cout<<i<<" ";
			}
		}
		return 0;
	}else{
		if(n==m){
			for(long long i=1;i<=m;i++){
				for(long long j=1;j<=n;j++){
					if(a[j]==i){
						cout<<j<<" ";
					}
				}
			}
			return 0;
		}else{
			for(long long i=1;i<=m;i++){
				cout<<i;
			}
		}
	}
	return 0;	
}
