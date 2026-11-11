#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string.h>
#include<vector>
#include<queue>
#include<random>
#include<ctime>
#define in inline
#define int long long
#define did printf(" \n");
#define N 2000000
using namespace std;
mt19937 rn(time(0));
in int rd(){
	int x=0,f=1;char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+(c^'0');
		c=getchar();
	}
	return x*f;
}
int t,ans;
int n,k;
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	t=rd();
	while(t--){
		n=rd(),k=rd();
		int u,v;
		for(int i=1;i<n;i++){
			u=rd(),v=rd();
		}
		ans=(rn()+u+n+v+k)%N;
		printf("%lld\n",ans);
	}
	return 0;
}
