#include<bits/stdc++.h>
using namespace std;
int a[500010],pos[300010],v[500010],ans[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
	    int cnt=0;
	    memset(pos,0,sizeof(pos));
		for(int j=i;j<=n;j++){
			if(pos[a[j]]<=cnt&&pos[a[j]]){
				cnt=pos[a[j]];
			}else{
				v[++cnt]=a[j];
			}
			pos[a[j]]=cnt;
		}
		for(int j=1;j<=cnt;j++){
			ans[v[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
