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
int n,m,a[200010],ans;
bool cans[200010];
signed main(){
	NOTLE::NO_TLE();//samples:5
	freopen("and.in","r",stdin),frein=true;
	freopen("and.out","w",stdout),freout=true;
	refrein=(frein and not(freout));
	scanf("%d%d",&n,&m);
	if(refrein)	printf("%d %d\n",n,m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(refrein)	printf("%d ",a[i]);
		cans[i]=true;
	}
	if(refrein)	printf("\n");
	for(int j=30;j>=0;j--){
		int x=(1<<j),cnt=0;
		for(int i=1;i<=n;i++){
			if(cans[i] and (a[i]&x))	cnt++;
		}
		if(cnt>=m){
			ans|=x;
			for(int i=1;i<=n;i++){
				if(not(a[i]&x))	cans[i]=false;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
