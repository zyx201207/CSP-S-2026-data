#include<bits/stdc++.h>
#define longlong long long
//#define longlong __int128_t
#define ll (longlong)
namespace NOTLE{
	void NOTLE(){
		std::ios::sync_with_stdio(0),std::cin.tie(0),std::cout.tie(0);
		return;
	}
	void NO_TLE(){
//		std::ios::sync_with_stdio(0),std::cin.tie(0),std::cout.tie(0);
		return;
	}
}
using namespace std;
bool frein=false,freout=false,refrein=false;
int n,m,a[500010],anses[300010];
void solveA(){
	for(int i=1;i<=n;i++){
		anses[a[i]]=max(anses[a[i]],n-i+1);
	}
	for(int i=1;i<=m;i++)	printf("%d ",anses[i]);
	printf("\n");
	return;
}
void solvem(){
	int X=a[n];
	anses[X]++;
	for(int i=1;i<=n;i++){
		if(a[i]!=X)	anses[a[i]]++;
	}
	printf("%d %d \n",anses[1],anses[2]);
	return;
}
void solve(){
	vector < bool > cnt(n+10,false);
	stack < int > stk;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(not(cnt[a[j]]))	stk.push(a[j]);
			else{
				while(stk.top()!=a[j]){
					cnt[stk.top()]=false;
					stk.pop();
				}
			}
		}
		while(not(stk.empty())){
			anses[stk.top()]++;
			stk.pop();
		}
	}
	for(int i=1;i<=m;i++)	printf("%d ",anses[i]);
	printf("\n");
	return;
}
bool flag=true,maxx;
signed main(){
	NOTLE::NO_TLE();//samples:6
	freopen("card.in","r",stdin),frein=true;
	freopen("card.out","w",stdout),freout=true;
	refrein=(frein and not(freout));
	scanf("%d%d",&n,&m);
	if(refrein)	printf("%d %d\n",n,m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(refrein)	printf("%d ",a[i]);
		if(a[i]<maxx)	flag=false;
		else	maxx=a[i];
	}
	if(refrein)	printf("\n");
	if(m==2){
		solvem();
		return 0;
	}
	if(flag){
		solveA();
		return 0;
	}
	solve();
	return 0;
}
