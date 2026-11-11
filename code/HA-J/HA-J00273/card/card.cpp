#include<bits/stdc++.h>
using namespace std;
int q[200000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+1];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int c[n+1],f[n+1];
		for(int j=1;j<=n;j++){
			c[j]=0;
			f[j]=1;
		}
		for(int j=i;j<=n;j++){
			bool o=0;
			for(int k=1;k<j;k++){
				if(c[k]==a[j]&&f[k]==1){
					o=1;
					f[k]=0;
				}
				if(o==1){
					f[k]=0;
				}
			}
			
			if(o==1){
				f[j]=0;
			}
				c[j]=a[j]
			
		}
		for(int j=1;j<=n;j++){
			if(f[j]==1){
				q[c[j]]++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<q[i];
		if(i!=n){
			cout<<' ';
		}
	}
	return 0;
}
