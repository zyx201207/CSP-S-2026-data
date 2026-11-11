#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],c[500005],bj=1,ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(c[a[j]]!=0){
				long long z=bj;
				bj=c[a[j]];
				for(int l=c[a[j]]-i+1;l<=z-1;l++){
					c[b[l]]=0;
					b[l]=0;
				}
				c[a[j]]=j;
			}else{
				c[a[j]]=j;
			}
			b[bj]=a[j];
			bj++;
		}
		for(int j=1;j<=n;j++){
			ans[b[j]]++;
		}
		memset(c,0,sizeof(c));
		bj=1;
		memset(b,0,sizeof(b));
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
