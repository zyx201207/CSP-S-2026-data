#include<bits/stdc++.h>
using namespace std;

int n,m,ans[300005],b[300005],a[500005];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int t=n,cnt=1;
	while(t--){
		memset(b,0,sizeof(b));
		for(int i=cnt;i<=n;i++){
			if(b[a[i]]!=0){
				for(int j=b[a[i]];j<=i;j++){
					b[a[j]]=0;
				}
			}
			b[a[i]]=i;
		}
		for(int i=1;i<=m;i++){
			if(b[i]!=0){
				ans[i]++;
			}
		}
		cnt++;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
