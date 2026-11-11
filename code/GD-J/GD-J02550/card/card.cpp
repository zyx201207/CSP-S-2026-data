#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	const int N=1e6;
	int n,m,a[N],b[N],c[N];
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++){
		int ans=0;
		for(int j=i;j<=n;j++){
			b[ans++]=a[j];
			for(int t=0;t<=ans;t++){
				if(b[t]==a[j]){
					ans=t;
					break;
				}
			}
		}
		for(int j=1;j<=m;j++){
			c[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		if(i==1) cout<<c[i];
		else cout<<" "<<c[i];
	}
	
	return 0;
} 
