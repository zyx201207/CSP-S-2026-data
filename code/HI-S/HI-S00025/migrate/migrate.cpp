/*
这个对的前提是
有一组边 i-j-k-p
 k-i<=d p-j<=d
那么就一定是优美对
而且如果更长就死了 
这是N^3的，可以拿到24分

然后不妨考虑一下如何优化
一开始我们的思路是枚举所有的 i,j 然后线性check
那能不能做到把所有的这样的一组好边给存出来
因为好边似乎是4个点成一对的
所以如果a[i-3]到a[i+3]有其他的 1
那么这些全都是死点，标为-1 
假设已经标出来所有的活点和死点了那就是一个排列问题
比方说两个死点构成的区间 (l1,r1) 中间的活点 x
那么左端点L就只能在 (l1,x] 取
右端点R就只能在 [x+3,r1) 取
意思就是取点只能取一对活点，不能有死点 

那么考虑如何求活点和死点可以O(N)? 

差点见祖宗
这个对的前提是（upd)
k-i<=d p-j<=d p-i>d 

现在稳拿的分是 1-2,11-12
也就是只有16分
总分100+0+16+0，输了，还剩两小时
第二题快翻啊 
感觉仍然在大众分范围内
第四题还没看第二题还没理解题意（16:36） 
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
int C;
void solve_n4(){
	int n,d; cin >>n >>d;
	vector<int>a(n+5,0);
	int ans=0;
	fr(i,1,n){
		cin >>a[i];
	}fr(i,1,n){
		fr(j,i,n){
			bool flag=1;
			//check
			fr(k,i+1,j){
				if(a[k]-a[k-1]>d){
					flag=0;
					break;
				}
			}if(!flag||a[j]-a[i]<=d) continue;
			int cnt=0;
			fr(k1,i+1,j-2){
				fr(k2,k1+1,j-1){
					//[i,k1,k2,j]
					if(a[k2]-a[i]<=d&&a[j]-a[k1]<=d)
						cnt++;
				}
			}
			//done
			if(cnt==1) {
				ans++;
				//cout << ":" << i <<' ' <<j <<endl;
			} //if(i==1&&j==6) cout << cnt << "[]\n";
		}
	}cout <<ans << "\n";
}/*
6 12
-10 -6 -2 2 6 10
变成n^4做法了。草 
*/
void solve(){
	int n,d;cin >>n >>d;
	vector<int>a(n+5,0),f(n+5,0);
	fr(i,1,n) {
		cin >>a[i];
		if(i>1&&a[i]-a[i-1]>d) f[i]=-1;
	}
	fr(i,4,n){
		//判断 ai ai-1 ai-2 ai-3是否是一组优美对
		if(a[i]>1){
			continue;
		}
	}
}
void solve_A(){
	int n,d; cin >>n >>d;
	vector<int>a(n+5,0);
	fr(i,1,n) cin >>a[i];
	if(n==1){
		cout <<"0\n";
		return;
	}int x=a[2]-a[1];
	if(!(d>=2*x)) cout <<"0\n";
	else{
		d/=x;
		int P=d*2;
		cout << max(0LL,n-P+1) <<endl;
	}
}void solve_BC(){
	cout << "0\n";
} 
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	fastIO();
	int T=1;
	cin >>C >>T;
	//cout << C;
	while(T--){
		if(C<=6) {
			//cout << "!";
			solve_n4();
		}
		else if(11<=C&&C<=12) solve_A();
		else if(13<=C&&C<=18) solve_BC();
	}return 0;
}
