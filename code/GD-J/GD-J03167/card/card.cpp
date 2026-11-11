#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[500005],cnt[300005];
int q[500005];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
//		
//	freopen("card2.in","r",stdin);
//	freopen("card2.out","w",stdout);
//	
	int n,m;
	cin>>n>>m;
	bool order=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]) order=0;
	}
	if(order){
		for(int i=1;i<=m;i++)cout<<i<<' ';
		return 0;
	}
	for(int i=1;i<=n;i++){//每局游戏 
		int idx=0;
		for(int j=i;j<=n;j++){//a[j]为当前牌 
			q[++idx]=a[j];
			for(int k=1;k<idx;k++){
				if(q[k]==q[idx]){
					for(int l=k;l<=idx;l++) q[l]=0;
					idx=k;
					q[idx]=a[j];
				}
			}
		}
		for(int j=1;j<=idx;j++){
			cnt[q[j]]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<' ';

	return 0;
}
