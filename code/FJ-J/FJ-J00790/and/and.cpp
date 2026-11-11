#include<bits/stdc++.h>
using namespace std;

int n,m,power[30],a[200005],cnt[30],ans=(1<<30)-1;
bool book[200005][30];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	for(int i=0;i<=29;i++)
		power[i]=(1<<i);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int ai=a[i];
		for(int j=29;ai>0;j--){
			if(ai>=power[j]){
				ai-=power[j];
				book[i][j]=true;
				cnt[j]++;
			}
		}
	}
	for(int i=29;i>=0;i--){
		if(cnt[i]==0) continue;
		sort(a+1,a+n+1,greater<int>());
		if(cnt[i]<m){
			for(int j=1;j<=cnt[i];j++)
				a[j]-=power[i];
			continue;
		}
		n=cnt[i];
	}
	for(int i=1;i<=m;i++){
		ans&=a[i];
	}
	cout<<ans;
	return 0;
}
