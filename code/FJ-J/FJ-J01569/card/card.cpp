#include<bits/stdc++.h>
using namespace std;int a[500005],b[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];b[a[n]]=1;
	for(int i=1;i<n;i++){
		int e[n+5]={0},w[m+5]={0};
		for(int j=i;j<=n;j++){
			if(w[a[j]]==0){
				w[a[j]]=j;e[j]=a[j];
			}
			else {
				for(int z=w[a[j]];z<j;z++){
					w[e[z]]=0,e[z]=0;
				}
				e[j]=a[j],w[a[j]]=j;
			}
		}
		for(int j=1;j<=m;j++){
			if(w[j]!=0)b[j]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<b[i]<<' ';
	return 0;
	
}
