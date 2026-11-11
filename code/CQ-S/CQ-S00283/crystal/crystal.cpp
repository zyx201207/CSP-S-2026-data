#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace T1{
	const int MAXN=5e5+5;
	int N,M,Ans;
	int a[MAXN];
	int d[MAXN];
	int s[MAXN];
	inline int Binary(int id){
		int L=1,R=id-1,Res=0;
		while(L<=R){
			int Mid=(L+R)>>1;
			if((id-Mid)*a[id]-(s[id-1]-s[Mid-1])<=M){
				Res=Mid;
				R=Mid-1;
			}
			else L=Mid+1;
		}
		if(!Res)return 0;
		return id-Res+1;
	}
	signed main(){
		freopen("crystal.in","r",stdin);
		freopen("crystal.out","w",stdout);
		ios::sync_with_stdio(0);
		cin.tie(0);cout.tie(0);
		cin>>N>>M;
		for(int i=1;i<=N;i++)cin>>a[i];
		sort(a+1,a+1+N);
		for(int i=1;i<=N;i++)s[i]=s[i-1]+a[i];
		for(int i=1;i<=N;i++)Ans=max(Ans,Binary(i));
		cout<<Ans;
		return 0;
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	T1::main();
	return 0;
}
//内存：12336KB
//时间：O(NlogN)
//预估分数：100pts 
