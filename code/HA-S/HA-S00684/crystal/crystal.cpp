#include<bits/stdc++.h> 
using namespace std;
long long n,m,maxx=-1e18;
long long a[500009];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];		 
	}
	sort(a+1,a+1+n);
	for(long long i=a[1];i<=a[n];i++){              //a[j]<=i
		long long op=0,sd=0,gs=0;
		for(long long j=n;j>=1;j--){   
			if(a[j]<=i){
				sd=abs(i-a[j]);
				op+=sd;
				if(op<=m){
					gs++;	
				}     
			}
		}
		if(gs>maxx){
			maxx=gs;
		}
	}
	cout<<maxx<<endl;
	return 0;
}
