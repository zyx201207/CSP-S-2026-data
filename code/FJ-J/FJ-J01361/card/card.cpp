#include<bits/stdc++.h>
using namespace std;
int a[5*100000+10];
int t[3*100000+10];
int xb[5*100000+10];
int n,m;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(xb,0,sizeof(xb));
		for(int j=i;j<=n;j++){
			if(xb[a[j]]!=0)
				for(int k=xb[a[j]];k<=j;k++){
					xb[a[k]]=0;
				}
			xb[a[j]]=j;
		}
		for(int j=1;j<=m;j++){
			if(xb[j]) t[j]++;
		}
	
	}
	for(int i=1;i<=m;i++){
	cout<<t[i]<<" ";
	}
	return 0;	
} 
