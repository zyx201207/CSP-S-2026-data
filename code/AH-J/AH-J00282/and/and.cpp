#include <bits/stdc++.h>
using namespace std;
long long n,m,maxx;
long long a[300000];
int main(){
    freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
		if(a[i]>maxx){
			maxx=a[i];
		}
	}  	
	if(m==1){
		cout<<maxx;
		return 0;
	}
	if(m==2){
		maxx=0;
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=n;j++){
				if((i!=j) && ((a[i]&a[j])>maxx)){
					maxx=a[i]&a[j];
				}
			}
		}
		cout<<maxx;
		return 0;
	}
	if(m==n){
		maxx=a[1];
		for(long long i=1;i<=n;i++){
			maxx=(maxx&a[i]);
		}
		cout<<maxx;
	}
	return 0;
}
