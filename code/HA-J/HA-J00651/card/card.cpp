#include<bits/stdc++.h>
using namespace std;
struct n{
	int l=0,t=0;
}f[300010];
int n,m,a[500010],e[500010];
int fid(int r){
	for(int i=1;i<=n;i++) if(e[i]==r)return i;
	return -1;
}
int change(int g){
	int k=0;
	for(int i=g+1;i<=n;i++){
		e[i]=-1;
		k++;
	}
	return k;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	memset(e,-1,sizeof e);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[i].l=i;
	}
	int h=n;
	int b=1;
	while(h--){
		memset(e,-1,sizeof e);
		for(int i=b,j=1;i<=n;i++){
			int q=fid(a[i]);
			if(q==-1){
				e[j]=a[i];
				j++;
			}else{
				int k=change(q);
				j=n-k+1;
			}
		}
		for(int i=1;i<=n;i++) f[e[i]].t++;
		b++;
	}
	for(int i=1;i<=m;i++) cout<<f[i].t<<' ';
	return 0;
}
