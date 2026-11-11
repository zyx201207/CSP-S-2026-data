#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000000],b[1000000],c[1000000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		int ans=0;
		for(int j=i;j<=n;j++){
			bool s=1;
			for(int l=1;l<=ans;l++){
				if(b[l]==a[j]){
					ans=l;
					s=0;
				}
			}
			if(s){
				ans++;
				b[ans]=a[j];
			}
		}
		for(int j=1;j<=ans;j++)
			c[b[j]]++;
	}
	for(int i=1;i<=m;i++)
		cout<<c[i]<<" ";
		return 0;
}
