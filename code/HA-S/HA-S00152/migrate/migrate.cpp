#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3fll
#define uint unsigned int
#define ulong unsigned long
using namespace std;

namespace AeeE5x{
	int n;
	long long d,a[2000010];
	
	int lpos[2000010],rpos[2000010];
	
	bool check(int s,int t){
		long long sum1=t,sum2=s;
		for(int i=s;i<t;i=rpos[i]){
			sum1+=i;
			if(i==rpos[i]) return false;
		}
		for(int i=t;i>s;i=lpos[i]){
			sum2+=i;
			if(i==lpos[i]) return false;
		}
		return sum1-sum2==1;
	}
	
	void main(){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		
		for(int i=1,lp=1,rp=1;i<=n;i++){
			while(a[i]-a[lp]>d) lp++;
			while(rp<n&&a[rp+1]-a[i]<=d) rp++;
			lpos[i]=lp,rpos[i]=rp;
		}
		
		long long ans=0;
		for(int x=1;x<=n;x++) for(int y=x+1;y<=n;y++) ans+=check(x,y);
		cout<<ans<<"\n";
	}
	
	void clear(){}
}

int main(){
//	freopen("samples\\migrate\\migrate4.in","r",stdin);
//	freopen("samples\\migrate\\migrate.out","w",stdout);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->sync_with_stdio(false);
	
	int testid,T;cin>>testid>>T;
	while(T--) AeeE5x::main(),AeeE5x::clear();
	
	#ifdef TakanashiHoshino
	cerr<<"\nUsed time: "<<clock()*1.0/CLOCKS_PER_SEC<<"s.\n";
	#endif
	return 0;
}

/*

Oct31==Dec25?

migrate

*/
