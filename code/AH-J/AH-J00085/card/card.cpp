#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[500005],ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++){
		int c=0;
		for(int j=i,k;j<n;j++){
			for(k=0;k<c;k++) if(b[k]==a[j])break;
			c=k;
			b[c++]=a[j];
		}
		for(int j=0;j<c;j++) ans[b[j]]++;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
