#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],tail[300005],ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	int top=0;
	for(int i=n;top<=m;i--){
		if(tail[a[i]]==0){
			tail[a[i]]=i;
			top++;
		}
	}
	int l;
	for(int i=1;i<=n;i++){
		l=i;
		for(int j=1;n-l+1<=3;j++) l=tail[a[l]];
		for(int j=l;j<=n;j++) ans[a[j]]++;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
