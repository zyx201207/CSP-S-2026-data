#include<iostream>  
using namespace std;
int n,m,a[500001],b[500001],cnt,ct[500001];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i]; 
	for(int i=1;i<=n;i++){
		cnt=0;
		for(int j=i;j<=n;j++){
			int k;
			for(k=1;k<=cnt;k++)
			  if(a[j]==b[k]) break;
			if(k!=cnt+1) cnt=k;
			else b[++cnt]=a[j];
		} 
        for(int j=1;j<=cnt;j++) ct[b[j]]++;
	}
	for(int i=1;i<=m;i++) cout<<ct[i]<<" ";
}
