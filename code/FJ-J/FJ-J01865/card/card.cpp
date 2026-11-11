#include <bits/stdc++.h>
using namespace std;
int mani(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[1005];
	
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int j=1,p[1005];
	for(int i=1;i<=n-(j-1);i++){
		if(a[i]!=p[i]){
			p[i]=a[i];
		}
	for(int j=1;j<=n;j++){
		if(a[i]==p[j]){
			p[1005]-=p[j];
			p[j]=a[i];
		}
	}
	j++;
	int cnt[m]={};
	if(p[j]==cnt[j]){
		cnt[j]++;
	}
	}
	for(int b=1;b<=m;b++){
		cout<<cnt[b];
	}
	
	return 0;
}
