#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],b[500010],f[300010],ans[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(f,0,sizeof(f));
		memset(b,0,sizeof(b));
		int l=0;
		for(int j=i;j<=n;j++){
			if(!f[a[i]]){
				b[++l]=a[i];
				f[a[i]]=l;
			}
			else{
				l=f[a[i]];
				f[a[i]]=l;
			}
		}
		for(int k=1;k<=l;k++){
			ans[b[i]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
