#include<bits/stdc++.h>
//#define F(i,a,b) for(register int i=a;i<=b;i=-~i)
//#define fre(o) freopen(#o".in","r",stdin),freopen(#o".out","w",stdout)
#define F(i,a,b) for(int i=a;i<=b;i++)
#define ll long long
using namespace std;const int N=5e5+67,M=3e5+67;
int n,m,a[N],mina[M],maxa[M];ll ans[M],sum[M];bool f;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	F(i,1,n){
		cin>>a[i];
		sum[a[i]]++;
		maxa[a[i]]=max(maxa[a[i]],i);
		if(i!=1&&a[i]<a[i-1])f=1;
	}if(f==0){//A
		F(i,1,m){
			sum[i]+=sum[i-1];
			cout<<sum[i]<<' ';
		}return 0;
	}F(i,1,n){
		F(j,i,n){
			if(j>=maxa[a[j]])ans[a[j]]++;
			else j=maxa[a[j]]-1;
		}
	}F(i,1,m)cout<<ans[i]<<' ';
	return 0;
}//baoli 54~100pts
/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1
*/
