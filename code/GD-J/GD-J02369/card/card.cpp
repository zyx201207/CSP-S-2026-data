#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,a[N],c[N],ans[N],ap[N],yes,cur;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int t=1;t<=n;t++){
		for(int i=t;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(c[j]==a[i]){
					yes=1;
					c[j]=0,ap[a[i]]=0,cur--;
				} 
				else if(yes) c[j]=0,ap[a[i]]=0,cur--;
			} 
			c[++cur]=a[i];
			ap[a[i]]=1;
		}
		for(int i=1;i<=m;i++) {
			if(ap[i]) ans[i]++;
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
