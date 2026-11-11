#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200050],b[200050][35],ans;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int x=a[i],t=0;
		while(x){
			t++;
			if(x%2==1){
				b[i][t]=1;
				b[n+1][t]++;
			}
			x/=2;
		}
	}
	for(int i=30;i>=1;i--){
		if(b[n+1][i]>=m){
			for(int j=1;j<=n;j++){
				if(b[j][i]==0){
					for(int s=i;s>=1;s--){
						if(b[j][s]==1){
							b[n+1][s]--;
							b[j][s]=0;
						}
					}
				}
			}
		}
	}
	
	for(int i=1;i<=30;i++){
		if(b[n+1][i]>=m){
			ans+=pow(2,i-1);
		}
	}
	cout<<ans;
	return 0; 
} 
