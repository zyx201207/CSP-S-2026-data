#include<bits/stdc++.h>
using namespace std;

const int N=2e5+5;
int n,m,a[N];
int idx=0,nxt[30*N][2],cnt[30*N];

bool checkA(){
	for(int i=1;i<=n;++i){
		if((a[i]&(a[i]+1))){
			return false;
		}
	}
	return true;
}

void solveA(){
	sort(a+1,a+n+1,greater<int>());
	int ans=a[1];
	for(int i=2;i<=m;++i){
		ans&=a[i];
	}
	cout<<ans<<'\n';
}

/*
bool checkB(){
	for(int i=1;i<=n;++i)
}
*/
void insert(int x){
	int u=0;
	for(int i=29;i>=0;--i){
		int c=x>>i&1;
		if(!nxt[u][c]){
			nxt[u][c]=++idx;
		}
		u=nxt[u][c];
		++cnt[u];
	}
}

int query(){
	int u=0,res=0;
	for(int i=29;i>=0;--i){
		int s1=nxt[u][1];
		int s0=nxt[u][0];
		if(s1>0&&cnt[s1]>=m){
			u=s1;
			res|=(1<<i);
		}else if(s0>0){
			u=s0;
		}else{
			break;
		}
	}
	return res;
}

void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	
	if(checkA()){
		solveA();
		return;
	}
	
	for(int i=1;i<=n;++i){
		insert(a[i]);
		int x=a[i];
		for(int j=29;j>=0;--j){
			if((x>>j)&1){
				x^=1<<j;
				insert(x);
			}
		}
	}
	cout<<query()<<'\n';
}

/*
猜想..好像不对 
ans=a[n]
for(i=n-1...0)
ans&=a[n-i+1]
*/

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t=1;
	while(t--) solve();

	return 0;
}
/*
从高往低考虑
i=29~0
if cnt[1]>=m
	选择1 res|=(1<<i)
else
	将第i位全部置换成0，低位仍参与后续统计

将每个数字的后缀全部存进去
for31 31 15 7 3 1
for28 28 12 4  
这样去掉高位之后，低位仍然能参与计数 

时间：O(n*30*30)=1.8e8 很险 
空间：O(n*30) 部分RE 
 我们希望时空O(30n)或者常数更小一点
*/
