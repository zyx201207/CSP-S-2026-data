#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,l,r,ans,t;
struct op{
	ll v;
	ll f;
}a[200005],b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		char s;
		cin>>a[i].v>>s;
		a[i].f=s-'a'+1;
	}	
	for(int i=1;i<=n;i++){
		if(a[i].f!=a[i-1].f){
			b[++m].f=a[i].f;
			b[m].v+=a[i].v;
		}else{
			b[m].v+=a[i].v;
		}
	}
	l=1;
	r=m;
	while(l!=r&&l<r)//kaishi
	{
		if(b[l].f==b[r].f)//dangxiangtongshi
		{
			if(b[l].v==b[r].v)//dixiao
			{
				l++;
				r--;
			}else if(b[l].v>b[r].v)//dayu
			{
				b[l].v-=b[r].v;
				r--;
			}else if(b[l].v<b[r].v)
			{
				b[r].v-=b[l].v;
				l++;
			}
		}else//buxiangdengshi
		{
			if(b[l].v==b[r].v)
			{
				ans+=b[l].v;
				l++;
				r--;
			}else if(b[l].v>b[r].v)
			{
				ans+=b[r].v;
				b[l].v-=b[r].v;
				r--;
			}else if(b[l].v<b[r].v){
				ans+=b[l].v;
				b[r].v-=b[l].v;
				l++;
			}
		}
	}
	cout<<ans;
	return 0;
}
