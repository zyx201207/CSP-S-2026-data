#include<bits/stdc++.h>

using namespace std;

const int N=2e5+10;
int a[N];
int cnt[N];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		cnt[a[i]]=max(cnt[i],i); 
	}
	for(int i=1;i<=m;i++)cout<<cnt[i]<<' ';
	
	return 0; 
} 
