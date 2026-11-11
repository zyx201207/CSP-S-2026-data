#include <bits/stdc++.h>
#define int long long 
#define F(i,l,r) for(int i=l;i<=r;i++)
#define E(i,r,l) for(int i=r;i>=l;i--)
#define Luogu return
#define _DEQUE_ 0
using namespace std;

const int N=5e5+5;

void fre(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
}

int m,n,a[N];

bool check(int x){
	int l=1,r=1,res=0;
	for(;r<=x;r++){
		res+=a[x]-a[r];
	}//这里显然 r 会多一位 
	if(res<=m)return 1;//直接特判掉 
	for(;r<=n;r++){ 
		res-=a[r-1]-a[l];
		res+=(a[r]-a[r-1])*(x-1);
//		cout<<res<<endl;
		if(res<=m){
//			cout<<res<<endl;
			return 1;
		}
		l++;
	}
	return 0;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	fre();
	cin>>n>>m;
	F(i,1,n)cin>>a[i];
	sort(a+1,a+n+1);
	int l=1,r=n,ans=1;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}else{
			r=mid-1;
		}
//		cout<<mid<<endl;
	}
	cout<<ans;




	Luogu _DEQUE_;
}

