#include<bits/stdc++.h>
using namespace std;
int dui[500010];
int cnt[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		cnt[x]+=i;
		dui[i]=x;
	}
	for(int i=1;i<=n;i++){
		for(int j=1+i;j<=n;j++){
			if(dui[j]==dui[j-1]){
				cnt[dui[j]]--;
				cout<<cnt[1];
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<' ';
	}
	return 0;
} 
