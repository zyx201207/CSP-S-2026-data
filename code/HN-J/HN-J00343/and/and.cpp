#include <bits/stdc++.h>

#define fr for
//#define int long long

inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch<'0'||ch>'9'){
		f|=ch=='-';ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return f?-x:x;
}

using namespace std;

const int N=2e5+7;

/*
都 2026 年了，我怎么还在考 J 组？

qwertyuiop[]\asdfghjkl;'
zxcvbnm,./`

4 2
 3 15 12 12
 
 5 3
31 3 1 15 7

奶龙题目，直接秒了，鉴定为 <T2 
*/
int a[N];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout) ;
	vector<int>cur;
	int n=read(),m=read(),ans=0;;
	fr(int i=1;i<=n;i++)a[i]=read(),cur.push_back(a[i]);
	fr(int i=30;~i;i--){
		vector<int>nxt;
		int cnt=0;
		fr(auto x:cur){
			if((x>>i)&1)cnt++;
		}
		if(cnt<m){//完全不可能凑出来这一位 
//		cerr<<(1<<i)<<' '<<cnt<<"!!!\n";
			continue;
		}
		ans|=(1<<i);
//		cerr<<"!!!"<<(1<<i)<<"---\n";
		fr(auto x:cur){
			if((x>>i)&1)nxt.push_back(x);
		}
		swap(cur,nxt);
	}
	cout<<ans;
	return 0;
}

