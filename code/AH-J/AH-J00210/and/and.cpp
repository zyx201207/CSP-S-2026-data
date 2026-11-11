#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,x2[200005][70],xx;
struct node{
	long long id,zh,cn;
};
node a[200005];
long long a_nd(long long x,long long y){
	long long ans2=0;
	for(int i=35;i>=0;i--){
		if(x>=pow(2,i)){
			x-=pow(2,i);
			if(x2[y][i]==1)
				ans2+=pow(2,i);
		}
	}
	return ans2;
}
bool cmp(node x,node y){
	if(x.cn!=y.cn)
		return x.cn>y.cn;
	else
		return x.zh>y.zh;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].zh;	
		a[i].id=i;
		xx=a[i].zh;
		for(int j=35;j>=0;j--)
			if(xx>=pow(2,j)){
				xx-=pow(2,j);
				x2[i][j]=1;
				a[i].cn++;
			}	
	}
	sort(a+1,a+n+1,cmp);
	ans=a[1].zh;
	for(long long i=2;i<=m;i++)
		ans=a_nd(ans,a[i].id);
	cout<<ans;
	return 0;
}
