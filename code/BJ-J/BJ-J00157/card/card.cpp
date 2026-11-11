#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
	}	
	int tp[2000005]={0};
	tp[a[n]] = n;
	for(int i = 1;i<=n;i++){
		for(int j = 1;j<=m;j++){
			if([i]==n&&a[i]!=a[i+1]&&j!=a[n])tp[j]++;
		}
	}
	for(int i = 1;i<=m;i++)
		cout <<tp[i]<<" ";
	return 0;
}