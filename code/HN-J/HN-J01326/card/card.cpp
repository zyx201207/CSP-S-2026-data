#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans,Ans[300005];
struct node{
	int p,cnt;
}H[300005];
bool ok;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;++i){
		cin>>a[i];
		if (a[i]<a[i-1] && i!=1){
			ok=1;
		}
	}
	if (!ok){
		for (int i=1;i<=n;++i){
			for (int j=1;j<=10000;++j) H[j].cnt=0;
			for (int j=i;j<=n;++j){
				H[a[j]].cnt=1;
			}
			for (int j=1;j<=10000;++j){
				if (H[j].cnt==1){
					++Ans[j];
				}
			}
		}
	}
	else {
		for (int i=1;i<=n;++i){
			ans=0;
			for (int j=1;j<=1005;++j) H[j].cnt=0;
			for (int j=i;j<=n;++j){
				if (H[a[j]].cnt>=1){
					for (int I=H[a[j]].p;I<j;++I){
						--H[a[I]].cnt;
					}
					continue;
				}
				else {
					++H[a[j]].cnt;
					H[a[j]].p=j;
					++Ans[a[j]];
				}
			}
		}
	} 
	for (int i=1;i<=m;++i) cout<<Ans[i]<<' ';
	return 0;
}
/*
4 3
1 2 1 3
*/
