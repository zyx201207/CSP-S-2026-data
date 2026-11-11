#include<bits/stdc++.h>
using namespace std;
int cnt=0,n,m,a[5001],b[5001],dis[3001];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	cin>>a[0];
	for(int i=1;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i+=1){
		for(int j=i;j<n;j+=1){
			for(int k=1;k<=cnt;k+=1){
				if(b[k]==a[j]){
					cnt=k-1;
					break;
				}
			}
			cnt++;
			b[cnt]=a[j];
		}
		for(int k=1;k<=cnt;k+=1){
			dis[b[k]]++;
		}
		for(int k=1;k<=cnt;k+=1){
			b[k]=0;
		}
		cnt=0;
	}
	for(int k=1;k<=m;k+=1){
		cout<<dis[k];
	}
	return 0;
} 
