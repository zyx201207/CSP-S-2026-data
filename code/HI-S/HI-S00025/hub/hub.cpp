/*
18:02开题，我还想翻
发现A性质是显然的，可以在m/2±k/2的位置进行科研
那么更显然的是A性质的结果只由1节点旁边那个和
m节点旁边那个决定
如何巧妙运用除以二性质？分类讨论
如果m是个偶数，那么k是奇数则k/2+1个放>M，k/2个放<M
			   如果k是偶数则k/2个放>M，k/2个放<M
如果m是个奇数，那么k是偶数则k/2+1个放>M，k/2-1个放<M
			   如果k是奇数则k/2+1个放>M，k/2个放<M
 
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
void solve_A(){
	int n,k; cin >> n >> k;
	frr(i,1,n){
		int x,y; cin >>x >>y;
	}
	int m=n/2;
	if(k>=m+2){
		cout <<0 <<endl;
		return;
	}else if(k==m+1){
		cout <<1 <<endl;
		return;
	}//现在k<=m
	int l=m/2,r=m/2;
	if(m%2==0){
		if(k%2==1) { r+=k/2+1; l-=k/2; }
		else {
			r+=k/2;
			l-=k/2;
		}
	} else{
		if(k%2==1){
			r+=k/2+1;
			l-=k/2-1;
		}else{
			r+=k/2+1;
			l-=k/2;
		}
	}int minleft=l;
	int minright=m-r+1;
	//cout << minleft <<' ' <<minright <<endl;
	int ans1=max(minleft,minright);
	int left=k/2;
	int right=k/2+k%2;
	right=m+m%2-right-1;
	int ans2=(right-left)/2+(right-left-1)%2;
	cout <<ans1/2+(right-left)%2 <<endl;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	fastIO();
	int c,t; cin >>c >>t;
	while(t--){
		solve_A();
	}
	return 0;
}
