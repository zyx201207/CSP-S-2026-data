#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],c[300001];
int main(){
	freopen("card.in","r",stdout);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		int t[500001],top=0;
		for(int j=i;j<=n;j++){
			int addr=top;
			for(int k=1;k<=top;k++)if(t[k]==a[i])addr=k;
			if(addr!=top)top=addr;
			else t[++top]=a[i];
		}
		for(int j=1;j<=top;j++)c[t[j]]++;
	}
	for(int i=1;i<=m;i++)cout<<c[i]<<' ';
} 
