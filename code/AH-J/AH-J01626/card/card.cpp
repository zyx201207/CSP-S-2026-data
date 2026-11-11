#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],cnt[300005],b[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			cnt[a[j]]++;
			if(cnt[a[j]]>1){
				int k=i;
				for(;k<j;k++){
					if(a[k]==a[j]) break;
				}
				for(;k<j;k++){
					cnt[a[k]]=0;
				}
				cnt[a[j]]=1;
			}
		}
		for(int j=1;j<=m;j++){
			b[j]+=cnt[j];
//			cout<<cnt[j]<<' ';
			cnt[j]=0;
		}
//		cout<<'\n';
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<' ';
	}
	return 0;
} 
