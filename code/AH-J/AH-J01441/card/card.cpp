#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,a[N],c[N];
int mp[N];
int zm[N];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) mp[i]=-1;
	for(int w=1;w<=n;w++){
		int tot=0;
		for(int i=w-1;i<=n;i++){
			if(mp[a[i]]==-1) zm[++tot]=a[i],mp[a[i]]=tot;
			else{
				while(tot>=mp[a[i]]){
					mp[zm[tot]]=-1;
					tot--;
				}
			}
		}
		while(tot){
			c[zm[tot]]++;
			mp[zm[tot]]=-1;
			tot--;
		}
	}
	for(int i=1;i<=m;i++) printf("%d ",c[i]);
	cout<<endl;
	return 0;
}
