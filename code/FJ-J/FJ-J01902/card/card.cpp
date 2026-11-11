#include <bits/stdc++.h>
using namespace std;

bool flag[300005];
int a[500005],b[300005],n,m,ans[300005];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		b[a[i]]=i;
	}
	for(int i=0;i<n;i++){
		fill(flag+1,flag+1+m,1);
		for(int j=i+1;j<=n;j++){
			if(b[a[j]]!=j){
				j=b[a[j]]-1;
			}
			else{
				ans[a[j]]+=flag[a[j]];
				flag[a[j]]=0;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
