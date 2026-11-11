#include<bits/stdc++.h>
using namespace std;
int a[500005],b[300005],c[300005];
bool p[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,q; 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		for(int j=1;j<=m;j++){
			p[j]=0;
		}
		for(int j=1+i;j<=n;j++){
			if(p[a[j]]==0){
				p[a[j]]=1;
				b[a[j]]++;
			}
			for(int k=j+1;k<=n;k++){
				if(a[j]==a[k]){
					j=k;
				}
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<' ';
	}
	return 0;
} 
