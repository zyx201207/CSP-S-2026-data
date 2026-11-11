#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010],ans[500010],k[500010],f[500010];
int mp[300010],ji[500010];
int minn[300010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
		cin>>a[i];
		if(mp[a[i]]){
			f[mp[a[i]]]=i;
		}
		mp[a[i]]=i;
	}
	int now=1;
	for(int i=1;i<=n;i++){
		now+=ji[i];
		ans[i]=now;
		if(f[i]){
			now=0;
			ji[f[i]]+=ans[i];
		}
		now++;
	}
	for(int i=1;i<=n;i++)minn[a[i]]=max(minn[a[i]],ans[i]);
	for(int i=1;i<=m;i++)cout<<minn[i]<<" ";
    return 0;
}
