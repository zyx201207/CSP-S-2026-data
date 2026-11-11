#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int s[500001],b[500001]; 
int ml=0x7fffff;
int at(int k){ 
	int sum=0;int z=0;
	for(int i=k;i>=1;i--){
		if(s[k]-s[i]>=0){
			if(sum+(s[k]-s[i])<=m){
				sum+=(s[k]-s[i]);
				z++;
			}
			else return z;
		}
	}return z;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&s[i]);
	}sort(s,s+n);
	for(int i=1;i<=n;i++){
		ans=max(at(i),ans);
	}printf("%d",ans);
	return 0;	
}
/*
	5 5
	1 2 4 8 9
	5 8 
	-3 -1 2 2 7
	*/
