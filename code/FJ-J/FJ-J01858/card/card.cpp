#include<bits/stdc++.h>
using namespace std;
int a[505],b[505],c[505],cnt[505];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	if(m==1){
		if(n%2==1){
			cout<<n/2+1;
		}
		else{
			cout<<n/2;
		}
	}
	else{
		for(int i=1;i<=n;i++){
			cin>>a[i];
			b[i]=a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=i-1;j++){
				if(a[i]!=b[j]){
					c[i]=a[i];
				}
				else{
					for(int k=i;k<=j;k++){
						c[k]=0;
					}
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cnt[c[i]]++;
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cout<<cnt[j]<<" ";
			}
		}	
	}
	return 0;
} 
