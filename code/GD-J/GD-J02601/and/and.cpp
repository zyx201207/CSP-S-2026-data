#include<bits/stdc++.h>
//#define F(i,a,b) for(register int i=a;i<=b;i=-~i)
//#define fre(o) freopen(#o".in","r",stdin),freopen(#o".out","w",stdout)
#define F(i,a,b) for(int i=a;i<=b;i++)
#define D(i,a,b) for(int i=a;i>=b;i--)
#define F1(i,a,b,c) for(int i=a;i<=b;i=c)
#define ll long long
using namespace std;const int N=2e5+67; 
int n,m;ll a[N],u[N],v[N],ans,sum;bool vis[N];
void dfs(int num,ll ad){
	if(num>=m){ans=max(ans,ad);return;}
	F(i,1,n){
		if(vis[i]==0){
			vis[i]=1;
			dfs(num+1,ad&a[i]);
			vis[i]=0;
		}
	}return;
}int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;v[0]=1,u[n+1]=n;
	F(i,1,n)cin>>a[i],u[i]=i,v[i]=i+1;
	if(n<=2000){
		F(i,1,n){
			vis[i]=1;
			dfs(1,a[i]);
			vis[i]=0;
		}cout<<ans;
		return 0;
	}D(i,30,0){
		sum=0;
		F1(j,v[0],n,v[j])if(a[j]&(1ll<<i))sum++;
		if(sum>=m){
			ans+=(1ll<<i);
			F1(j,v[0],n,v[j])if(a[j]&(1ll<<i)==0)v[u[j]]=v[j],u[v[j]]=u[j];
		}
	}cout<<ans;
	return 0;
}//50~80pts

/*
4 2
3 15 12 12

5 3
31 3 1 15 7
*/
