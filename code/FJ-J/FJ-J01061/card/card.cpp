#include<bits/stdc++.h>
using namespace std;

const int N=5e5+5;
const int M=3e5+5;
int n,m,a[N],ans[M];
int nxt[N];
vector<int> ve[M];

bool checkA(){
	for(int i=1;i<n;++i){
		if(a[i]>a[i+1]){
			return false;
		}
	}
	return true;
}

bool checkB(){
	int cnt=0;
	for(int i=1;i<n;++i){
		if(a[i]!=a[i+1]){
			++cnt;
			if(cnt>4999){
				return false;
			}
		}
	}
	
	return true;
}

void solveA(){
	for(int i=n;i>=1;--i){
		if(a[i]!=a[i+1]){
			ans[a[i]]=i;
		}
	}
}

void solveB(){
	for(int l=1;l<=n;l=nxt[l]+1){
		for(int i=l;i<=n;i=ve[a[i]][ve[a[i]].size()-1]+1){
		 	ans[a[i]]+=(nxt[l]-l+1);
		}
	}
}

void solveM(){
	for(int i=1;i<=n;++i){
		++ans[a[i]];
		if(ve[a[i]][ve[a[i]].size()-1]!=a[i])
			++ans[3-a[i]];
	}
}

void solve_slow(){
	for(int l=1;l<=n;++l){
		for(int i=l;i<=n;i=ve[a[i]][ve[a[i]].size()-1]+1){
			++ans[a[i]];
		}
	}
}

void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		ve[a[i]].push_back(i);
	}
	
	nxt[n+1]=n+1; 
	for(int i=n;i>=1;--i){
		if(a[i]==a[i+1]){
			nxt[i]=nxt[i+1];
		}else{
			nxt[i]=i;
		}
	}
	/*
	for(int i=1;i<=n;++i){
		cout<<nxt[i]<<" \n"[i==n];
	}*/
	
	if(n<=5000){
		solve_slow();
	}else if(checkA()){
		solveA();
	}else if(checkB()){
		solveB();
	}else if(m==2){
		solveM();
	}else{
		solve_slow();
	}
	
	for(int i=1;i<=m;++i){
		cout<<ans[i]<<" \n"[i==m];
	}
}

/*
10 3
3 1 2 1 3 2 3 1 2 1
1:2-4-8-10
2:3-6-9
3:1-5-7
[1,10]:3 1
[2,10]:1
[3,10]:2 1
[4,10]:1
[5,10]:3 1
[6,10]:2 1
[7,10]:3 1
[8,10]:1
[9,10]:2 1
[10,10]:1
ans[]={10,3,3}
单次复杂度O(n)
原因：1 2 3 4 ...各不相同的构造
使得复杂度退化 
 
*/

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t=1;
	while(t--) solve();

	return 0;
}
/*
O(n^2)做法
枚举左端点i=1~n
对每个区间[i,n]跑一遍
*/
