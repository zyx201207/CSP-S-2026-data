#include<bits/stdc++.h>
using namespace std;
long long sum=0;
int n,m,a[500005],b[500005];
bool vis[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i]==a[j]){
				vis[i]=1;
				vis[j]=1;
			}
			
		}
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==0){
			sum+=a[i];
		}
		if(vis[i]==1){
			sum+=a[i];
			b[i]=sum;
			sum=0;
		}
		
	} 
	for(int i=1;i<=m;i++){
		cout<<sum<<" ";
	}
	return 0;
}
