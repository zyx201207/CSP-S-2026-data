#include<bits/stdc++.h>
using namespace std;
int a[200005];
bool b[200005][32];
int c[35];
int ans=0;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int t=1;a[i]>=1;t++){
			if(a[i]%2==1){
				c[t]++;
				b[i][t]=1;
			}
			else{
				b[i][t]=0;
			}
			a[i]/=2;
		}
	}
	for(int i=30;i>=1;i--){
		if(c[i]>=m){
			ans+=pow(2,i-1);
			for(int j=1;j<=n;j++){
				if(b[j][i]==0){
					for(int k=1;k<=30;k++){
						if(b[j][k]==1){
							c[k]--;
							b[j][k]=0;
						}
					}
				}
			}
		}
	}
	cout<<ans;
	return 0;
} 
