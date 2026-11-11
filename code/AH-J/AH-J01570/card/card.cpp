#include<bits/stdc++.h>
using namespace std;
int n,m,t;
int a[500005],res[500005],cnt[500005],ans[500005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt[a[i]]++;
	}
	for(int i=1;i<=n;i++){
		t=0;
		for(int j=i;j<=n;j++){
			bool f=0;
			int pos=1;
			for(int k=1;k<=t;k++)
				if(res[k]==a[j]){
					pos=k;
					f=1;
					break;
				}
			if(!f){
				res[++t]=a[j];
			}else{
				t=pos-1;
				res[++t]=a[j];
			}			
		}
		for(int i=1;i<=t;i++)
			ans[res[i]]++;
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	return 0;
}
