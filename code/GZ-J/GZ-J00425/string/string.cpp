//GZ-J00425 王武涛 兴义市弘毅中学
#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n,i,ans=0,l,r;
struct Captial{
	unsigned ll num;
	char x;
};
vector<struct Captial> c;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++){
		struct Captial captial;
		scanf("%lld %c",&captial.num,&captial.x);
		c.push_back(captial);
	}
	l=0;
	r=n-1;
	while(l<r){
		ll d=min(c[l].num,c[r].num);
		if(c[l].x!=c[r].x)ans+=d;
		c[l].num-=d;
		c[r].num-=d;
		if(c[l].num<=0)l++;
		if(c[r].num<=0)r--;
	}
	printf("%lld",ans);
	printf("\n");
	return 0;
}

