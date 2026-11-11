#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,a[N],c[N],fir,ans[N],flag1=1,flag2;
int lst[N],ax;
struct node{
	int l,r;
	int x;
}b[N];
int sum[N],cnt[N];
void solve1(){
	for(int i=1;i<=n;i++){
		fir=0;
		for(int j=1;j<=n;j++) lst[j]=0,b[j]=node{0,0,0};
		for(int j=i;j<=n;j++){
			b[j].l=fir;
			b[j].x=a[j];
			fir=j;
			if(lst[a[j]]){
				int t=j;
				while(t&&t!=lst[a[j]]){
					t=b[t].l;
					if(t==lst[a[j]])break;
					lst[a[t]]=0;
				}
				b[j].l=b[lst[a[j]]].l;
				b[b[lst[a[j]]].l].r=j;
			}
			lst[a[j]]=j;
		}
		for(int j=1;j<=m;j++)if(lst[j]) ans[j]+=sum[i];
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
}
//void solve2(){
//	for(int i=n;i;i--)cnt[a[i]]++;
//	for(int i=1;i<=n;i++){
//		if(c[a[i]]==0){
//			c[a[i]]=i;
//			if(cnt[a[i]]%2) ans[a[i]]+=(i-1);
//		}
//	}
//	for(int i=1;i<=m;i++){
//		ans[i]=ans[i]+(cnt[i]+1)/2;
//		cout<<ans[i]<<" ";
//	}
//}
void solve3(){
	for(int i=1;i<=n;i++)c[i]=a[i];
	for(int i=1;i<=n;i++){
		if(c[i]==c[i-1])sum[ax]++;
		else{
			a[++ax]=c[i];
			sum[ax]=1;
		}
	}
	n=ax;
	solve1();
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>a[i-1])flag1=0;
		if(a[i]!=a[i+1]&&i!=n)flag2++;
	}
	if(n<=5000&&m<=3000){
		for(int i=1;i<=n;i++) sum[i]=1;
		solve1();
	}
	else if(flag2<=5000) solve3();
	else{
		for(int i=1;i<=n;i++) sum[i]=1;
		solve1();
	}
	return 0;
}
/*
4 3
1 2 1 3

可惜，终究是没能圆满 
*/

