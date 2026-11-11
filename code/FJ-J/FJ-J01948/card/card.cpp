#include<bits/stdc++.h>
using namespace std;
int n,m,nip,a[500005],sp[300005],li[500005],ans[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		nip=0;
		for(int j=i;j<=n;j++){
			if(sp[a[j]]==0){
				nip++;
				li[nip]=a[j];
				sp[a[j]]=nip;
			}
			else if(sp[a[j]]<=nip&&li[sp[a[j]]]==a[j]){
				nip=sp[a[j]];
			}
			else{
				nip++;
				li[nip]=a[j];
				sp[a[j]]=nip;
			}
		}
		for(int j=1;j<=nip;j++){
			ans[li[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
	return 0;
}
