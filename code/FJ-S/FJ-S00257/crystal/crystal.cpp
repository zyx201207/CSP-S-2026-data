#include<bits/stdc++.h>
using namespace std;
long long a[500050],q[500050];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	unsigned long long n,m,l,r,mid,ans=0;
	cin>>n>>m;
	for(long long i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++)q[i]=q[i-1]+a[i];
	for(long long i=1;i<=n;i++){
		l=1,r=i;
		while(l<r){
			mid=l+(r-l)/2;
			if(-q[i]+q[mid-1]+a[i]*(i-mid+1)>m)l=mid+1;
			else r=mid;
		}
		ans=max(i-r+1,ans);
	}
	cout<<ans;
	return 0;
} 
/* 
  English shui pin gen goshift yi yang
  2026.10.29 in florr.io A super Laser crafted by Lung_fog!
  zhi hui xie di yi ti zen me ban awa
  xi wang neng man fen ya 
  I want 100 points
  da yang li do guo le neng man fen ba?
  (zhekebuhaoshuo  
  I'm JuRuo   
  I must zuolao 3 hours(   
  jintianshiwoshengri=true  
  fan yi guan xin ku le,danshiruguowobakonggeshandiaohuizenmeyang     
  biruzhejuhaikandedongma?     
  meishizhexiejuziqishishenmeyisiyemeiyou     
  luogu@Lung_fog
*/
