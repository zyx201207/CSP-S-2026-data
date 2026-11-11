#include<bits/stdc++.h>
using namespace std;

long long n,m,a[500005],cnt,maxx;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	
	sort(a+1,a+1+n);
	if(n<=8000){
		for(long long i=1;i<=n;i++){
			long long mx=m,f=1;
			for(long long j=i;j<n;j++){
				long long xy=a[j+1]-a[j];
				if(xy*(j-i+1)>mx){
					maxx=max(maxx,(j-i+1));
					f=0;
					break;
				}else{
					mx-=xy*(j-i+1);
				}
			}
			if(f==1){
				maxx=max(maxx,(n-i+1));
			}
			
		}
		cout<<maxx;
	}else{
		for(int i=1;i<n;i++){
			int xy=a[i+1]-a[i];
			if(xy*i>m){
				cout<<i;
				return 0;
			}else{
				m-=xy*i;
			}
		}
		cout<<n;
	}
	
	return 0;
} 
