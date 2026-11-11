#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+5;
typedef long long ll;
#define qwq(x) freopen(x ".in","r",stdin);freopen(x ".out","w",stdout);
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define rrep(x,y,z) for(int x=z;x>=y;x--)

int n;
ll a[MAXN],m;


//14:28 got the problems
//14:30 read T1
//14:40 thinking
//14:47 Chtholly bless me
//15:03 Complete

//If someone makes "Misunderstooding Behaviors Show" on Luogu,Please at(@): XYMAPLE,__SeaWave__,setnight_,cat98132
//author: Luogu @zhenzhang
//Luogu @setnight AK CSP-J

//Hold fair Olympics

//I often recall the past.
//The pieces of time flash back,froze,I ___ it and fold it,cut it into the clouds behind me.
//There's difference between clouds and clouds
//then I forget
//"Where should I stop?"I ask myself.

int main(){
	#ifndef off
	qwq("crystal");
	#endif
	
	scanf("%d %lld",&n,&m);
	rep(i,1,n){
		scanf("%lld",a+i);
	}
	sort(a+1,a+n+1);
	
	int j=1,ans=1;
	ll sum=a[1];
	
	rep(i,1,n){
		while(j<=n&&sum+m>=a[j]*(j-i+1)){
			#ifdef debug
			printf("%d %d %lld\n",i,j,sum);
			#endif
			sum+=a[++j];
		}
		ans=max(ans,j-i);
		sum-=a[i];
		
	}
	
	printf("%d\n",ans);
}