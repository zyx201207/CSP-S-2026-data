#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
struct node{
	int a1[35],w;
	ll v;
}a[N];
int n,m,ans[35],k[35],ma;
bool vis[N]={0};
void read(int x){
	ll s,cnt=1;
	int i=1;
	cin>>s;
	while(s!=0){
		if(s%2==1){
			a[x].a1[i]=1;
			k[i]++;
			a[x].v+=cnt;
		}
		s/=2;
		cnt*=2;
		i++;
	}
	a[x].w=i-1;
}
bool cmp(node a,node b){
	return a.v>b.v;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) read(i);
	for(int i=30;i>0;i--){
		if(k[i]>1){
			ma=i;
			break;
		}
	}
	for(int i=1;i<=ma;i++) ans[i]=1;
	ll cnt=1;
	for(int i=1;i<=ma;i++) cnt*=2;
	for(int i=1;i<=n;i++) a[i].v%=cnt;
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=ma;j++){
			if(a[i].a1[j]==0) ans[j]=0;
		}
	}
	cnt=1;
	ll sum=0;
	for(int i=1;i<=ma;i++){
		if(ans[i]==1) sum+=cnt;
		cnt*=2;
	}
	cout<<sum;
	return 0;
}
