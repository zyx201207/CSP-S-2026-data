#include<bits/stdc++.h>
using namespace std;
long long n,m,a[600000],q[600000],w[600000],e[600000];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	long long x=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		e[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			q[a[j]]++;
			if(q[a[j]]==2){
				for(int k=1;k<=m;k++){
					q[k]=0;
				}
				q[a[j]]++;
			}
		}
		for(int j=1;j<=m;j++){
			if(q[j]>0){
				w[j]++;
			}
		}
		for(int k=1;k<=m;k++){
			q[k]=0;
		}
	}
	for(int i=1;i<=m;i++){
		if(e[i]!=0){
			cout<<w[i]<<" ";
		}
	}
	return 0;
} 
