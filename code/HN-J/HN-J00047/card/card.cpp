#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5e5+7;
int n,m,a[maxn],cnt[maxn],idl[maxn],idr[maxn],ans[maxn],w[maxn];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			cnt[a[j]]++;
			if(cnt[a[j]]==1){
				idl[a[j]]=j;
			}else{
				idr[a[j]]=j;
			}
		}
		for(int j=i;j<=n;j++){
			if(j==idl[a[j]]&&idr[a[j]]!=0){
				j=idr[a[j]];
				ans[a[j]]=1;
			}else if(idr[a[j]]>j&&idr[a[j]]!=0){
				j=idr[a[j]];
				ans[a[j]]=1;
			}else{
				ans[a[j]]=1;
			}
		}
		for(int j=1;j<=m;j++){
			w[j]+=ans[j];
			ans[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<w[i]<<" ";
	}
	return 0;
}
