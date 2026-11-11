#include<bits/stdc++.h>
#include<cmath>
#define ll long long
#define N 200010
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

ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}  

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	
	return 0;
}
