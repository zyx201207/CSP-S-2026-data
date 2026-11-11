#include<bits/stdc++.h>
using namespace std;
int n,m,a[10005],bucket[10005],tt[100005],ans[10005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	for(int i=1;i<=n;++i){
		int ok=-1;
		for(int j=1;j<=m;++j){
			bucket[j]=INT_MAX;
		}
		for(int j=i;j<=n;++j){
			if(ok==-1){
				bucket[a[j]]=1;
				ok=1;
				continue;
			}
			if(bucket[a[j]]>ok||bucket[a[j]]==INT_MAX){
				bucket[a[j]]=ok+1;
				++ok;
			}else{
				ok=bucket[a[j]];
			}
		}
		for(int j=1;j<=n;++j){
			tt[a[j]]=ans[a[j]];
		}
		for(int j=1;j<=n;++j){
			if((bucket[a[j]]<=ok)&&tt[a[j]]==ans[a[j]]){
				++ans[a[j]];
//				cout<<i<<' ';
//				break;
			}
		}
//		cout<<endl;
	}
	for(int i=1;i<=m;++i){
		cout<<ans[i]<<' ';
	}
	return 0;
}
