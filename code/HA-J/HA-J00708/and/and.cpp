#include <bits/stdc++.h>
#define int long long
#define F(i,l,r) for(int i=l;i<=r;i++)
#define E(i,r,l) for(int i=r;i>=l;i--)
#define Luogu return
#define _DEQUE_ 0
using namespace std;

const int N=2e5+5;

int n,m;

void fre(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
}

struct Node{
	int sum;
	bitset<35>s;
}a[N];

void add(int x,int y){
	int res=1;
	while(y){
		a[x].s[res++]=y%2;
		y/=2;
	}
}

bool cmp(Node a,Node b){
	return a.sum>b.sum;
}

int o;

bool cmp2(Node a,Node b){
	return a.s[o]>b.s[o];
}

int maxx;

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	fre();
	cin>>n>>m;
	F(i,1,n){
		cin>>a[i].sum;
		add(i,a[i].sum);
		maxx=max(maxx,a[i].sum);
	}
	sort(a+1,a+n+1,cmp);
	int r=n,l=1,res=0;
	int k=21;
	if(maxx>(1ll<<20))k+=10;
	if(maxx<=(1ll<<10))k-=10;
	E(i,k,1){
		o=i;
		sort(a+1,a+r+1,cmp2); 
		int cnt=0,pr=r;
		F(j,1,r){
			if(a[j].s[i]){
//				cout<<i<<" "<<j<<endl; 
				cnt++;
				pr=j;
			}
		}
		if(cnt>=m){
//			cout<<i<<" "<<cnt<<endl;
			r=pr;
			res+=(1ll<<i-1);
//			cout<<i<<endl;
		}
	}
	cout<<res<<endl;
	
	



	Luogu _DEQUE_;
}//172.16.12.5
//remember to check your code,you didn't use "define int long long" or "fre()"
/*
别急别急，急也没用
首先贪心选择高的是没问题的
但是高的也要内部排序
这么做均摊 log^2 了啊 
不过 noip2024T4，nlog^2n 可是跑了 5e5 的，这是 2e5 
算了扔了，十一点回来看 
*/
