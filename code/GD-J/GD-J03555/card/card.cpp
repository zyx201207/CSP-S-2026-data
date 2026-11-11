#include<bits/stdc++.h>
using namespace std;
int tong[500010];
int ans[500010];
int a[500010];
int b[500010];
long long n,m;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>b[n-i+1];
	} 

	
	for(int i=1;i<=n;i++){
		tong[b[i]]++;
		if(tong[b[i]]>=2){
			for(int j=1;j<=i;j++){
				ans[b[j]]++;
				if(tong[b[j]]>=2){
					break;
				}
			}
		}
		else{
			for(int j=1;j<=i;j++){
				ans[b[j]]++;
			}
		}
		
	}
	for(int i=1;i<=500010;i++){
		if(ans[i]!=0){
			cout<<ans[i]<<" ";
		}
	}
	
	return 0;
} 
