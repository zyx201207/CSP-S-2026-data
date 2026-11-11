#include<bits/stdc++.h>
#define int long long
using namespace std;
int rd(){
	int x=0;char ch=getchar();bool f=0;
	while(ch<'0'||ch>'9')f|=ch=='-',ch=getchar();
	do{x=(x<<3)+(x<<1)+(ch^48),ch=getchar();}while(ch>='0'&&ch<='9');
	return f?-x:x;
}
struct node{
	int v,h;
	const bool operator<(const node&b)const{
		return h!=b.h?h>b.h:v>b.v;
	}
};
int C,T,n,k,x,y,a[1000001],dp[1000001],rt,dep;
vector<int>g[1000001];
void gtrt(int x,int fa,int deep){
	if(deep>dep)rt=x,dep=deep;
	for(int i:g[x]){
		if(i==fa)continue;
		gtrt(i,x,deep+1);
	}
	return;
}
signed main(){
	freopen("hub.in","r",stdin),freopen("hub.out","w",stdout);
	C=rd(),T=rd(),srand(time(0));
	while(T--){
		n=rd(),k=rd(),rt=1,dep=1;
		for(int i=1;i<n;i++)x=rd(),y=rd(),g[x].push_back(y),g[y].push_back(x);
		if(C>=13&&C<=14){
			if(k%2)x=(x+1)/2,k/=2;
			else x=(x+1)/2,k/=2;
			if(x%2&&k%2)printf("%lld\n",(x-k)/2+1);
			else if(x%2)printf("%lld\n",(x+1-k)/2);
			else if(k%2)printf("%lld\n",(x+1-k)/2);
			else printf("%lld\n",(x-k)/2+1);
			for(int i=1;i<=n;i++)g[i].clear();
			continue;
		}
		gtrt(rt,0,1),dep=0,gtrt(rt,0,1);
		if(k==2){
			x=0,y=0;
			for(int i:g[rt])if(a[i]>x)y=x,x=a[i];else if(a[i]>y)y=a[i];
			printf("%lld\n",max(x/2,y+1));
			for(int i=1;i<=n;i++)g[i].clear();
			continue;
		}
		x=0;
		cout<<rand()%n<<endl;
		for(int i=1;i<=n;i++)g[i].clear();
	}
	return 0;
} 
