#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3fll
#define uint unsigned int
#define ulong unsigned long
using namespace std;

namespace AeeE5x{
	int n;
	long long m,a[500010];
	long long pre[500010];
	
	bool check(int target){
		for(int i=target;i<=n;i++){
			long long sum=pre[i]-pre[i-target];
			long long mul=target*a[i];
			if(mul-sum<=m) return true;
		}
		return false;
	}
	
	void main(){
		cin>>n>>m;
		for(int i=1;i<=n;i++) cin>>a[i];
		
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++) pre[i]=pre[i-1]+a[i];
		
		int l=1,r=n;
		while(l<r){
			int mid=(l+r+1)>>1;
			if(check(mid)) l=mid;
			else r=mid-1;
		}
		
		cout<<l<<"\n";
	}
}

int main(){
//	freopen("samples\\crystal\\crystal4.in","r",stdin);
//	freopen("samples\\crystal\\crystal.out","w",stdout);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	
	AeeE5x::main();
	
	#ifdef TakanashiHoshino
	cerr<<"\nUsed time: "<<clock()*1.0/CLOCKS_PER_SEC<<"s.\n";
	#endif
	return 0;
}

/*

Oct31==Dec25?

crystal

°Ë·ÖÖÓÃëÁË¡£ 

*/
