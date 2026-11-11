#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+10,maxm=3e5+10;
int a[maxn];
int cnt[maxm];
int last[maxm];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m; 
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		last[a[i]]=i;
	} 
	for(int i=0;i<n;i++){
		int j=i;
		while(j<n){
			cnt[a[j]]++;
			j=last[a[j]]+1;
		}
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<" ";
	return 0;
} 
