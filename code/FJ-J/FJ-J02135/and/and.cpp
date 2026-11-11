//T3-如果我想要的话我应该是可以拿到#1~#15的 
//40pts
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e5+5;

int n,m,a[maxn],ans,tot,mx;
bool fg13=1;

bool chk(int num){
	num++;
	while(num>1){
		if(num%2!=0){
			return 0; 
		}
		num/=2; 
	}
	if(num!=1){
		return 0;
	}
	return 1;
}

bool cmp(int x,int y){
	return x>y;
}

void dfs(int id,int step){
	if(n-id<m-step)
		return;
	if(tot<=ans)
		return;
	if(step==m+1){
		ans=max(ans,tot);
		return;
	}
	for(int i=id+1;i<=n;i++){
		int tmp=tot;
		tot=tot&a[i];
		dfs(i,step+1);
		tot=tmp;
	}
}

signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(a[i],mx);
		if(chk(a[i])==0){
			fg13=0;
		}
	}
	if(m==1){//#6 
		cout<<mx;
		return 0;
	}
	if(m==n){//#7
		int sum=a[1];
		for(int i=2;i<=n;i++){
			sum&=a[i];
		}
		cout<<sum;
		return 0;
	}
	if(fg13==1){//#13
		sort(a+1,a+n+1,cmp); 
		cout<<a[m];
		return 0;
	}
	if(n<=20&&m<=n){//#1~#5
		tot=(1<<30)-1;
		dfs(0,0);
		cout<<ans;
		return 0;
	}
	sort(a+1,a+n+1,cmp);
	cout<<a[m];
	return 0;
}
/*
A:全部都是1...1这样->对于&运算，就是全局第m大的数 
B:数的个数是二的幂，数字是序号-1
	这个意味着序列是0~n-1，然后n-1还是1...1这样的数
	那m是全局
A:
5 2
1 3 7 15 31

1~5:
4 2
3 15 12 12

5 3
31 3 1 15 7

6:
4 1
3 15 12 12

7:
4 4
3 15 12 12
*/
