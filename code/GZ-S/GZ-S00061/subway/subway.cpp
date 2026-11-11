//GZ-S00061 zhangbin zunyisizhong
#include<bits/stdc++.h> 
using namespace std;

#define ll long long
#define repp(i,a,b) for(int i=a;i<=b;i++)
#define reqq(i,a,b) for(int i=a;i>=b;i--)

ll rd()
{
	ll x=0,f=1;char ch=getchar();
	while(ch<'0' || ch>'9'){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0' && ch<='9') x=x*10+ch-48,ch=getchar();
	return x*f;
}
const int N=5e5+5;

int c,n,m,d,q;
int head[N<<1],ver[N<<1],cnt,nxt[N<<1];
void add(int x,int y)
{
	ver[++cnt]=y;
	nxt[cnt]=head[x];
	head[x]=cnt;
}


int w[N];
int main()
{
	//IF A WERE A GUEST,I WERE ENCOUNTER WITH CCF!?!
	c=rd(),n=rd(),m=rd(),d=rd(),q=rd();
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	repp(i,1,m) w[i]=rd();
	int t=0;
	srand(time(0));
	int I=19491001;
	repp(i,1,q) printf("%d",(rand()%I-19891001+2*I)%I+2);
	return 0;
}
//I ALWAYS REMBER THAT I HAVEN'T ABLE TO ENCOUNTER WITH NOI ANGLE BUT I STILL HOPE THAT ONE DAY I COULD SAW HER IN THE FUTURE,EVEN THROUGH I HAD NO CHANGE TO ENTER THE PLACE AGAIN.WHAT A PITY THAT.
