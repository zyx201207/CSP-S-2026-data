#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n, m; cin>>n>>m;
	int a[500001],pai[500001];
	int cnt[500001];
	for(int i=1;i<=n;i++) cin>>a[i];
	int x=1;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
		pai[x]=a[j]; x+=1;
        for(int o=1;0<x;o++){
        	if(pai[o]==a[j]){
        		for(int y=o;y<=j;y++) pai[y]=0;
			}
		}}
		for(int shao=1;shao<=i;shao++){
			for(int e=1;e<=m;e++){
			if(pai[shao]=e) cnt[e]+=1;}
		}
		cout<<cnt[1];
		x-=i;}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
	cout<<endl;
	return 0;
	}
