#include<bits/stdc++.h>
using namespace std;
#define int long long
int cc,tt;
namespace Quirrel_Subtask1{
//input
int n,m,a[5100];
//init
int id;
int l[5100],r[5100];
int ed[5100][5100];
int suml[5100][5100],sumr[5100][5100];
//output
int ans;
signed main(){
	cin>>n>>m;ans=0;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		l[i]=lower_bound(a+1,a+1+n,a[i]-m)-a;
		r[i]=upper_bound(a+1,a+1+n,a[i]+m)-a-1;
	}
	for(int i=1;i<=n;i++){
		id=i;
		for(int j=1;j<=n;j++){
			id=r[id];sumr[i][j]=sumr[i][j-1]+id;ed[i][j]=id;
		}
		id=i;
		for(int j=1;j<=n;j++){
			id=l[id];suml[i][j]=suml[i][j-1]+id;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=2;j<=n;j++){
			for(int k=ed[i][j-1]+1;k<=ed[i][j];k++){
				if(suml[k][j-1]+1==sumr[i][j-1])ans++;
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}
//
}
namespace Quirrel_Subtask2{
//input
int n,m,a[2000100];
//output
int ans;
signed main(){
	cin>>n>>m;ans=0;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(n==1||a[2]-a[1]>m){
		cout<<0<<"\n";return 0;
	}
	m/=(a[2]-a[1]);
	if(m==1){
		cout<<0<<"\n";return 0;
	}
	for(int i=1;i<=n;i++){
		if(i+2*m-1<=n)ans++;
	}
	cout<<ans<<"\n";
	return 0;
}
//
}
namespace Quirrel_Subtask3{
//input
int n,m,a[2000100];
//init
int l[2000100],r[2000100];
//solve
int idl,idr;
//output
int ans;
signed main(){
	cin>>n>>m;ans=0;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		l[i]=lower_bound(a+1,a+1+n,a[i]-m)-a;
		r[i]=upper_bound(a+1,a+1+n,a[i]+m)-a-1;
	}
	for(int i=1;i<=n;i++){
		if(r[i]<=i+1)continue;
		idr=r[r[i]-1];
		idl=r[r[i]-2];
		ans+=idr-idl;
	}
	cout<<ans<<"\n";
	return 0;
}
//
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>cc>>tt;
	if(cc<=10){
		while(tt--)Quirrel_Subtask1::main(); 
	}
	else if(cc<=12){
		while(tt--)Quirrel_Subtask2::main();
	}
	else{
		while(tt--)Quirrel_Subtask3::main();
	}
	return 0;
}
/*
剩下2h
做这一道题
56pts应该打得完 

打完了
但是这个Subtask3没有对应的大样例
没办法检查
而且感觉用来验证Subtask1和2的大样例也不强
静态查一下错吧 

The world breaks everyone,and afterward many are strong at the broken places. 
*/
