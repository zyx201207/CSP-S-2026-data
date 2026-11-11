#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],c[300005],cnt[200005],t,ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		t=0;
		for(int j=i;j<=n;j++){
			c[a[j]]++;
			if(c[a[j]]==2){
				for(int z=a[j]-1;z<=t;z++){
					cnt[z]=0;
					c[z]--;
				}
				t-=a[j];
			}
			cnt[t++]=a[j];
		}
		for(int j=0;j<t;j++){
			ans[cnt[j]]++;
			cnt[j]=0;
		}
		for(int j=1;j<=n;j++){
			c[a[j]]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
