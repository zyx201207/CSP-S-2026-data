#include<bits/stdc++.h>
#include<cmath>
#define ll long long
#define N 500010
#define For(i,a,b) for(register int i=a;i<=b;++i)
#define Rof(i,a,b) for(register int i=a;i>=b;--i)
#define ls x<<1
#define rs x<<1|1
#define lson ls,l,mid
#define rson rs,mid+1,r
#define pb push_back
#define mk make_pair
#define pque priority_queue

using namespace std;
ll s[N],a[N];
ll n,m,ans=1;

ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}  
ll calc(int l,int r){
	return a[r]*(r-l+1)-(s[r]-s[l-1]);
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	For(i,1,n) a[i]=read();
	sort(a+1,a+n+1);
	For(i,1,n) s[i]=s[i-1]+a[i];
	For(i,1,n){
		int l=1,r=i,p=i;
		while(l<=r){
			int mid=(l+r)>>1;
			if(calc(mid,i)<=m) p=mid,r=mid-1;
			else l=mid+1;
		}
		ans=max(ans,(ll)(i-p+1));
	}
	cout<<ans<<endl;
	return 0;
}
/*
Where there's a will,there's a way,kind of beautiful.
For every night has its day,so magical.
And if there's love in this life,there's no obstacles.
Nobody can be defeated.

For every tyrant a tear for the vulnerble.
________________________________________
For every dreamer a dream will unstoppable.
With something to believe in.

Monday left me broken.
Tuesday I will through with hoping.
Wednesday my empty arms are open.
Thursday I'm waiting for love,waiting for love.
Then they starts the Friday.
___________________________________
Yes I won't be coming to church on Sunday.
I'll be waiting for love,waiting for love.
So come around.
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
*/
