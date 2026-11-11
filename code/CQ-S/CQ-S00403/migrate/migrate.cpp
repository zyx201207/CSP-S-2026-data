#include<bits/stdc++.h>
using namespace std;

#define sht short
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define xwy114514 ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)

const ll INTINF=0x7f7f7f7f;
const ll LONGINF=0x3f3f3f3f3f3f3f3f;

const ll N=2e6+10;

ll c,T;
ll n,d,x[N];

ll dp16[N],cnt16[N];
void solve16(){
	ll ans=0ll;
	cin>>n>>d;for(ll i=1;i<=n;i++)cin>>x[i];
	for(ll l=1;l<=n;l++){
		for(ll i=l;i<=n;i++)dp16[i]=LONGINF,cnt16[i]=0ll;
		dp16[l]=0,cnt16[l]=1;
		for(ll i=l+1;i<=n;i++){
			for(ll j=l;j<i;j++){
				if(x[i]-x[j]>d)continue;
				if(dp16[j]+1<dp16[i]){
					dp16[i]=dp16[j]+1;
					cnt16[i]=cnt16[j];
				}else if(dp16[j]+1ll==dp16[i]){
					cnt16[i]+=cnt16[j];
				}
			}
		}
		for(ll i=l;i<=n;i++)if(cnt16[i]==2ll)ans++;
	}
	cout<<ans<<endl;
}


void solve16T(){while(T--)solve16();}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	xwy114514;
	
	cin>>c>>T;
	if(1<=c&&c<=6)solve16T();
	
	return 0;
}
/*

1 2
4 2
1 2 3 4
5 2
1 2 3 4 5
ok 现在还剩两个小时 我只需要当暴力仙人把后面多便宜点分就行了哈哈哈哈哈
200+[0,100]=[200,300]!!!!!!!

我感觉这个是分治

首先一个点能到达的一定是一段区间
那么线段树优化见图！pp 
 

大暴力，，，应该挺难的吧这个题

1~2:n<=9 那么直接dfs 9*9*9!<1e8
3~6:n<=300 直接暴力建图然后跑？ 不对 应该是克鲁斯卡尔？ 
关键是需要求解对数
能否O(n^2)求解 ?

如果线段树优化建图然后跑迪杰斯特拉的话复杂度多少？
 
发现不可能往回走，所以求的是？最短的单调上升子序列？
那么对于n<=300 就可做了 dp一下 记录最短和最短的数量,复杂度O(n^3)

24分 

然后考虑一下O(n^2)怎么做？

想一下 发现两点之间的最小距离其实能算出来？对于A可算
算了 打T4暴力吧。。。我不会了 
*/
