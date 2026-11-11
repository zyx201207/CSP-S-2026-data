#include<bits/stdc++.h>
using namespace std;
int a[500005],b[300005],ans[300005],c[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ans[a[i]]+=i;
		if(b[a[i]]==0){
			b[a[i]]=i;
		}
		else{
			for(int j=b[a[i]];j<i;j++){
				ans[a[j]]-=b[a[i]]-c[a[i]];
			}
			c[a[i]]=b[a[i]];
			b[a[i]]=i;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
