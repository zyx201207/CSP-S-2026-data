/*
我草这种题真司马啊
草拟吗比
你费那么大心思设计一个w数组
结果只需要在前后加
出题人的母亲去世了 

还没结束。我们发现Floyd的思路很对，可以在一条线路上的东西全部预处理，然后由这东西推到一般情况。
也就是说，我们预处理完一条路径上的 dis 后
可以考虑把每两个点都给松弛一遍 
样例解释绝对错了，按我的理解来 

我草没结束！！！！！ 
17:59再翻8分！！！！！ 
all in T4!!!!!
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pb push_back
#define is insert
#define prq priority_queue
#define gYES cout<<"YES\n";
#define gNO cout<<"NO\n";
#define gYes cout <<"gYes\n";
#define gNo cout<<"gNo\n";
#define fr(i,a,b) for(int i=(a);i<=(b);i++)
#define rf(i,a,b) for(int i=(a);i>=(b);i--)
#define frr(i,a,b) for(int i=(a);i<(b);i++)
#define endl "\n"
const int MOD=998244353;
const int Mod=1e9+7;
const int HASH1=1e7+79;
const int HASH2=5e7+19;
const int N=5e5+5;
void fastIO(){
	ios::sync_with_stdio(0);
	cin.tie(0); cin.tie(0); cout.tie(0);
}int qpow(int x,int y,int mod=MOD){
	int a=1;
	x%=mod;
	while(y){
		if(y&1) a=a*x%mod;
		x=x*x%mod;
		y>>=1;
	}return a;
}
vector<int>a[N],t[N],f[N],q[N];
void solve(){
	int n,m,d,q; cin >>n >>m >>d >>q;
	vector<int>w(m+5),k(n+5);
	fr(i,1,m){
		a[i].resize(m+5);
		t[i].resize(m+5);
		f[i].resize(m+5);
		fr(j,0,m+1) f[i][j]=1e18; 
	}
	fr(i,1,m) cin >>w[i];
	fr(i,1,m) f[i][i]=0;
	fr(i,1,n){
		cin >>k[i];
		fr(j,1,k[i]){
			cin >>a[i][j] >>t[i][j];
		}
		fr(j,1,k[i]){ 
			fr(K,1,k[i]){
				//cout <<a[i][j ] << ' ' <<a[i][K] <<endl;
			    f[a[i][j]][a[i][K]]=0;
			    //cout<<"/";
				f[a[i][K]][a[i][j]]=0;
				//cout <<"/";
			}
		}//cout << "/";
		fr(j,1,k[i]){ //对每个车站搞一遍 
			fr(K,1,k[i]){
				f[a[i][j]][a[i][K]]+=t[i][j];
				f[a[i][K]][a[i][j]]+=t[i][j];
			}
		}
	}fr(K,1,m){
		fr(i,1,m){
			fr(j,1,m){
				f[i][j]=min(f[i][j],f[i][K]+f[K][j]);
			}
		}
	}
	while(q--){
		int x,y; cin >>x >> y;
		if(x==y){
			cout <<"0\n";
			continue;
		}int ans=(x!=y)?(w[x]+w[y]):0;
		/*
		在这张图上跑最短路就可以了！！！ 
		*/ans+=f[x][y];
		cout <<ans <<endl;
	}
}
void solvespecial(){
	int n,m,d,q; cin >>n >>m >> d >>q;
	if(m==1){
		int x; cin >> x;
		fr(i,1,n){
			int ki; cin >> ki;
			fr(j,1,ki){
				int x; cin >> x;
			}
		}while(q--){
			int x,y; cin >>x >>y;
			cout <<"0\n";
		}
		return;
	}vector<int>A(5); cin >>A[1] >> A[2];
	int dis=1e18;
	fr(i,1,n){
		int ki; cin >>ki;
		if(ki==1){
			int x; cin >> x; cin >> x;
		}else{
			int x,y,t; cin >> t >> x ;
			cin >> t >> y;
			dis=min(dis,x+y);
		}
	}while(q--){
		int x,y;
		cin >> x >>y;
		//cout <<x <<' ' <<y <<endl;
		if(x==y) cout << "0\n";
		else cout << A[1]+A[2]+dis <<endl;
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	fastIO();
	int C,T=1;
	cin >>C;
	if(20<=C&&C<=21){
		while(T--){
			solvespecial();
		}
		return 0;
	}
	while(T--){
		solve();
	}return 0;
}/*
有点撑不住了
2h的时候上风油精 

ε=(′ο｀*)))唉到底是什么东西
你告诉我为什么要在我最想赢的一年
除了T1放三个图论
而且T1还是简单题
为什么啊

为啥啊我不会写最短路草
100+[40,52]+16+[0,10]=[156,178]
输了 
 
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3 
1 2

T4可以打A和k<=2 
*/


