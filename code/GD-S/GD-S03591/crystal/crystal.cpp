#include<bits/stdc++.h>
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define rf(i,a,b) for(int i=a;i>=b;i--)
#define ll long long
char Begin;
using namespace std;
const int N=5e5+15;
ll n,m,a[N],ans,S;
char End;
int main(){
	cerr<<(&End-&Begin)/1024/1024<<endl;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	fr(i,1,n)scanf("%lld",&a[i]);
	stable_sort(a+1,a+1+n);
	for(ll i=1,j=0;i<=n;i++){
		S+=(a[i]-a[i-1])*(i-j-1);
		while(S>m)S-=a[i]-a[++j];
		ans=max(ans,i-j);
	}printf("%d",ans);
}