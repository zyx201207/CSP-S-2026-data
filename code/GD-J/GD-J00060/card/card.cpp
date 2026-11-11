#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005];long long cnt[300005];
void game(int start,int end){
	if (start==end){
		cnt[a[start]]++;
		return ;
	}
	int idx;
	for (idx=start+1;idx<=end;idx++){
		if (a[idx]==a[start]){
			if (idx==end){
				cnt[a[idx]]++;
				return ;
			}
			game(idx,end);
			return ;
		}
	}
	cnt[a[start]]++;
	game(start+1,end);
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++) game(i,n);
	for (int i=1;i<=m;i++) cout<<cnt[i]<<' ';
	cout<<endl;
	return 0;
} 
