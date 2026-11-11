#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	long long a[1000005];
	long long max_n=0; 
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				max_n=max(max_n,a[i]);
			}
		}
		cout<<max_n;
	}
	
	else{
		for(int i=1;i<=n;i++){
			for(int j=n;j>=1;j--){
				if(a[i]==a[j]){
					max_n=max(max_n,a[i]);
				}
			}
		}
		cout<<max_n;
	}
	return 0;
}
