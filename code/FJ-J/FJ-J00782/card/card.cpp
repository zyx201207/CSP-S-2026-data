#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[300005],cnt[3000005],b[3000005];
queue<int> q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
		cnt[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]-3<<" ";
	}
	return 0;
}
