#include <bits/stdc++.h>
using namespace std;
int a[500005];
int cnt[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int t=1;t<=n;t++){
		for(int i=t+1;i<=n;i++){
			for(int j=t;j<=i-1;j++){
				if(a[i]==a[j]){
					for(int k=j;k<=i;k++){
						a[i]==0;
					}
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		cnt[a[i]]++;
	}
	int x_1=cnt[1];
	int x_2=cnt[3];
	for(int i=2;i<=m;i++){
		cnt[1]+=cnt[i];
	}
	cnt[1]=x_2*cnt[2]+1;
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
	return 0;
}

