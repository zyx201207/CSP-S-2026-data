#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],ans[300005];
int check(int x,int s){
	for(int i=1;i<=s;i++){
		if(x==b[i]){
			return i;
		}
	}
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int cnt=1;
		map<int,int>mp;
		for(int j=i;j<=n;j++){
			if(mp[a[j]]==0){
				b[cnt++]=a[j];
				mp[a[j]]++;
			}else{
				int c=check(a[j],cnt);
				for(int k=c;k<cnt;k++){
					b[k]=0;
				}
				cnt=c;
				b[cnt++]=a[j];
			}
		}
		for(int j=1;j<cnt;j++){
			ans[b[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
