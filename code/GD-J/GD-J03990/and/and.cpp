#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],k[200005][1000],ans,z[200005];
void er(long long x,int i){
	int h=0,s[1000],z;
	while(x){
		h++;
		s[h]=x%2;
		x/=2;
	}
	k[i][h+1]=2;
	z=h;
	for(int j=1;j<=h;j++)k[i][j]=s[z--];
}
long long find(long long w){
	int o=1,oo=0;
	while(k[w][o]!=2){
		oo++;
		o++;
	}
	return oo;
}
long long anweiyu(long long x,long long y){
	long long l1=find(x),l2=find(y),oo[10000],t=1,xans=0;
	for(int i=l1,j=l2;i>=1&&j>=1;i--,j--){
		if(k[x][i]==1&&k[y][j]==1){
			oo[t++]=1;
		}else{
			oo[t++]=0;
		}
	}
	xans+=oo[1]*1;
	for(int i=1;i<t-1;i++){
		for(int j=1;j<=i;j++)oo[i+1]*=2;
		xans+=oo[i+1];
	}
	return xans;
}
void dfs(int d,int cnt){
	if(cnt==m){
		long long key=0,h=z[1];
		for(int i=2;i<=cnt;i++){
			key=anweiyu(h,z[i]);
			h=z[i];
		}
		ans=max(ans,key);
	}
	if(d>=n)return;
	for(int i=d+1;i<=n;i++){
		z[cnt+1]=i;
		dfs(i,cnt+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		er(a[i],i);
	}
	dfs(0,0);
	cout<<ans;
	return 0;
}
