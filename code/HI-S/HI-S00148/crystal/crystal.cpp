#include<bits/stdc++.h>
using namespace std;
long long st[500005][20];
long long a[500005],pre[500005];
int lg2[500005];
int n;long long m;
void init(){
	lg2[0]=lg2[1]=0;
	for(int i=2;i<=n;i++){
		lg2[i]=lg2[i>>1]+1;
	}
	for(int i=1;(1<<i)<=n;i++){
		int l=1<<(i-1);
		for(int j=1;j+(1<<i)-1<=n;j++){
			st[j][i]=max(st[j][i-1],st[j+l][i-1]);
		}
	}
	return ;
}
long long query(int l,int r){
	int x=lg2[r-l+1],y=1<<x;
	return max(st[l][x],st[r-y+1][x]);
}
int find(int st){
	int j=st;
	for(int i=1<<20;i>0;i>>=1){
		if(j+i<=n){
			long long sum=query(st,j+i)*(long long)(j+i-st+1);
			sum-=pre[j+i]-pre[st-1];
			if(sum<=m)j+=i;
		}
	}
	return j;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;pre[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		st[i][0]=a[i];
		pre[i]=a[i]+pre[i-1];
	}
	init();
	int maxl=0;
	for(int i=1;i<=n;i++){
		int x=find(i);
		maxl=max(maxl,x-i+1);
	}
	cout<<maxl;
	return 0;
}
