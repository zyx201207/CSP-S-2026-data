#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define u_map unordered_map
const ll N=2e5+10,INF=0x3f3f3f3f,LINF=1e18+1;
int n,m,a[N],mx,ans;
struct node{
	int as,id,sx,kk;
};
bool cmp(int x,int y){
	return x>y;
}
//int BAOLI(int now,int as,int sx){
//	int sum;
//	if(now>=n) return as;
//	if(sx==0) return sum;
//	if(sx==m) 
//		as=a[now];
//	sum=max(BAOLI(now+1,as&a[now],sx-1),BAOLI(now+1,as,sx));
//	return as;
//}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(ans,mx);
	}
	if(m==1){
		ans=mx;
	}else if(m==2&&n<3e4){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
	}else if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++){
			ans&=a[i];
		}
	}/*else if(n<=20){
		ans=BAOLI(1,0,m);
	}*/else{
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=m;i++){
			if(i==1) ans=a[i];
			else ans&=a[i];
		}
	}
	cout<<ans;
	return 0;
}
