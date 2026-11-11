#include<bits/stdc++.h>
using namespace std;
int a[500005];
int cps[500005]={0};
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,ans=0,k;
	cin>>n>>m;
	for(int i=0;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		for(int j=0;j<=n-i;j++){
			k=a[i];
			cps[i]=a[i];
		}
		if(k==cps[i]){
			for(int j=i;j<n-i;j++)cps[i]=0;
			cps[i+1]+=a[i];
			for(int j=0;j<=i;j++){
				if(cps[i]=k){
					ans++;
				}
			}
			break;
		}
	}
	for(int i=0;i<=m;i++){
		cout<<ans;
	}
	return 0;
}
