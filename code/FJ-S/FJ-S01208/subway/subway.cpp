#include<iostream>
#include<cstdio>
using namespace std;
struct ST{
	int a=0;
	int b=0;
	int t=0;
};
ST _map[100005];
bool f[100005]={};
long long mi=0;
int dfs(int x,int y){
	if(x==y){
		return 0;
	}
	f[x]=1;
	long long min=1e9+1;
	int flag=0;
	for(int i=1;i<=mi;i++){
		if(_map[i].a==x&&f[_map[i].b]==0){
			flag=1;
			long long ans=dfs(_map[i].b,y)+_map[i].t;
			if(ans<min) min=ans;
		}else if(_map[i].b==x&&f[_map[i].a]==0){
			flag=1;
			long long ans=dfs(_map[i].a,y)+_map[i].t;
			if(ans<min) min=ans;
		}
	}
	f[x]=0;
	if(flag==0){
		return 1e9+1;
	}else{
		return min;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	int w[10005];
	for(int i=1;i<=m;i++){
		scanf("%d",&w[i]);
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int a[10005],t[10005];
		for(int j=1;j<=k;j++){
			scanf("%d%d",&a[j],&t[j]);
		}
		for(int g=1;g<k;g++){
			for(int h=g+1;h<=k;h++){
				mi++;
				_map[mi].a=a[g];
				_map[mi].b=a[h];
				_map[mi].t=t[g]+t[h];
			}
		}
	}
	int plan[10005][2];
	for(int i=1;i<=q;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		plan[i][0]=x;
		plan[i][1]=y;
	}
	for(int p=1;p<=q;p++){
		cout<<dfs(plan[p][0],plan[p][1])+w[plan[p][0]]+w[plan[p][1]]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
