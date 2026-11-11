#include<bits/stdc++.h>
using namespace std;
int ans[300005],s[300005],a[500005],b[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n;i++){
		memset(s,0,sizeof(s));
		memset(b,0,sizeof(b));
		for (int j=i;j<=n;j++){
			if (!s[a[j]]) {
				s[a[j]]=1;
				b[a[j]]=j;
			}
			else {
				for (int k=b[a[j]];k<j;k++){
					s[a[k]]=0;
					b[a[k]]=0;
				}
				b[a[j]]=j;
				s[a[j]]=1;
			}
		}
		for (int j=1;j<=m;j++){
			if (s[j]) ans[j]++;
		}
	}
	for (int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
