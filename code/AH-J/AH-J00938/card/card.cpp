#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cnt[200005];
ll n,m,a[200005],ans[200005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int k=1;k<=n-i;k++) cnt[k]=a[k+i-1];
	    for(int j=1;j<=n-i;j++){
			for(int k=j+1;k<=n;k++){
				if(cnt[j]==cnt[k]&&cnt[j]!=0){
					for(int x=j;x<k;x++){
						cnt[x]=0;
						}
					}
			}
			for(int c=1;c<=n-i;c++){
			    if(cnt[c]!=0) ans[cnt[c]]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
			cout<<ans[i]<<" ";
		}
	
	return 0;
}
