#include<bits/stdc++.h>
using namespace std;
#define qwq(x) freopen(x ".in","r",stdin);freopen(x ".out","w",stdout);
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define fi first
#define se second
typedef pair<int,int> pii;
typedef long long ll;
const int MAXN=2e5+5;

//Chtholly bless me

//08:40 read T2 
//08:55 codeing
//09:14 ate a piece of beef jerk
//09:21 RedBull from my dear coach
//09:28 %%%xiaoxiaozhang_123, pts come! pts come! 10 more! 20 more! 30 more!
//09:39 bubble gum
//Chinese Can Fly
//09:45 F,DevCpp has eaten my code
//09:53 check time cost,
//09:54 done T2,200pts has got

int n;
char c[MAXN];
int a[MAXN];
queue<pair<int,char> >q1,q2;
int RP;

int main(){
	#ifndef off
	qwq("string");
	#endif
	
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%d %c",a+i,c+i);
		RP++;
	}
	
	int l=1,r=n;
	ll ans=0;
	while(l<r){
		RP++;
		if(a[l]>a[r]){
			a[l]-=a[r];
			q1.push({a[r],c[l]});
			q2.push({a[r],c[r]});
			#ifdef debug
			printf("%d %c | %d %c\n",a[r],c[l],a[r],c[r]);
			#endif
			r--;
		}else if(a[l]<a[r]){
			a[r]-=a[l];
			q1.push({a[l],c[l]});
			q2.push({a[l],c[r]});
			#ifdef debug
			printf("%d %c | %d %c\n",a[l],c[l],a[l],c[r]);
			#endif
			l++;
		}else{
			q1.push({a[l],c[l]});
			q2.push({a[r],c[r]});
			#ifdef debug
			printf("%d %c | %d %c\n",a[l],c[l],a[r],c[r]);
			#endif
			l++;r--;
		}
	}
	
	
	
	while(q1.size()&&q2.size()){
		int lb=q1.front().fi,rb=q2.front().fi;
		char lc=q1.front().se,rc=q2.front().se;
		q1.pop();q2.pop();
		
		ans+=(lc!=rc?lb:0);
	}
	
	printf("%lld\n",ans);
}