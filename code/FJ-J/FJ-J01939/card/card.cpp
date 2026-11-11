#include<bits/stdc++.h>
using namespace std;
int a[500010],s[500010];
int cnt[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	cnt[a[n]]=n;	
	for(int i=1;i<=n;i++){
		s[a[i]]++;
	}
	for(int i=1;i<=m;i++){
		cnt[i]=s[a[i]];
	}
	cnt[a[n]]=n;
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
} 
