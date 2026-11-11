#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn=500010;
int energy[maxn],pref[maxn];
int n,m,ans;

void input(){
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&energy[i]);
	}
}
void solve(){
	sort(energy+1,energy+n+1);
	for(int i=1;i<=n;i++){
		pref[i]=pref[i-1]+energy[i];
	}
	for(int i=1;i<=n;i++){
		int L=0,R=i-1;//the num of getin one(other from this[i])
		while(L<R){
			int M=L+(R-L+1)/2;
			if(energy[i]*M - (pref[i-1]-pref[i-M-1]) <= m){
				L=M;//a possbile answer
			}else{
				R=M-1;//a impossbile answer
			}
		}
		ans = max(ans,L+1);
	}
}
void output(){
	printf("%lld",ans);
}
//void LunAsk(){}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	input();
	solve();
	output();
	return 0;
}
/*
      i
      ¡ý 
1 2 3 4
4*1 - (1+2+3 - 1+2)
*/









/*
I successfully kill this problem!
at 14:55

expect to get 100 FEN
*/
