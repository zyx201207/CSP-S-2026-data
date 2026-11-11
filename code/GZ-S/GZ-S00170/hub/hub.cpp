//GZ-S00170 张哲睿 贵阳市新世界学校
#include<bits/stdc++.h>
using namespace std;
int f[100100],sum=0,cnt=0;
int find(int x){
	if(f[x]==x) return x;
	else return f[x]=find(f[x]);
}
struct N{
	int u,v,w;
}e[100010];
bool cmp(N x,N y){
	return x.w<x.v;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		
	}
	for(int i=1;i<=n;i++){
		f[i]=i;
	}
	for(int i=1;i<=n;i++){
		cin>>e[i].u>>e[i].v>>e[i].w;
	}
	sort(e+1,e+1+n,cmp);
	for(int i=1;i<=n;i++){
		int x=e[i].u,y=e[i].v,z=e[i].w;
		if(find(x)==find(y)) continue;
		f[find(x)]=find(y);
		sum+=z;
		if(cnt==n-1){
			break;
		}
	}
	cout<<sum;
	return 0;
} 
