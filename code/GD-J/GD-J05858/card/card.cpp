#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
int ans[300010];
int f[300010];//f出现次数,s到i为止最后一个出现多于一个的 
map<int,int> nex;
map<int,int> mp;
void game(int x){
	int l=x,r;
	int v[300010],vv[300010];
	memset(v,0,sizeof(v));
	memset(vv,0,sizeof(vv));
	memset(f,0,sizeof(f));
	for(int i=x;i<=n;i++){
		if(v[a[i]]>0) l=i;
		else f[a[i]]=i;
		v[a[i]]++;
	}
	r=f[a[l]];
	for(int i=x;i<=f[a[l]];i++){
		vv[a[i]]++;
	}
	for(int i=x;i<=f[a[l]];i++){
		if(vv[a[i]]>1){
			r=i;
			break;
		}
	}
	for(int i=x;i<r;i++){
		ans[a[i]]++;
	}
	for(int i=l;i<=n;i++){
		ans[a[i]]++;
	}
	return;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		game(i);
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
