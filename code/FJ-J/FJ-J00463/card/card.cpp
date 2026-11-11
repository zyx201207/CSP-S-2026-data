#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m,a[N],ans[N],tmp[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	} 
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(tmp[a[j]]==0){
				tmp[a[j]]=1;
				ans[a[j]]++;
			}
		}
		memset(tmp,0,sizeof(tmp));
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
