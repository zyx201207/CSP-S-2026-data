#include<bits/stdc++.h>
using namespace std;
int a[505050],p[501010];
int c[1005050];
bool v[505050];
int fa[505050];
int n,m;
int len;
int minn;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=m;i++){
			v[i]=0;
			fa[i]=0;
		}
		for(int i=1;i<=n;i++){
			c[i]=0;
		}
		len=0;
		minn=1;
		for(int i=k;i<=n;i++){
			if(fa[a[i]]!=0&&fa[a[i]]>=minn&&fa[a[i]]<=len){
				len=fa[a[i]];
				c[len]=a[i];
			}else{
				len++;
				fa[a[i]]=len;
				c[len]=a[i];
			}
		}
		for(int i=minn;i<=len;i++){
			if(v[c[i]]==1){
				continue;
			}
			v[c[i]]=1;
			p[c[i]]+=1;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<p[i]<<' ';
	}
	return 0;
}

