#include<bits/stdc++.h>
#define int long long
using namespace std;

const int maxn=2e5+10;

int n,L;
int a[maxn];
char c[maxn];
int ans;

signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
//	freopen("string4.in","r",stdin);
//	freopen("string4.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;++i){
		cin>>a[i]>>c[i];
		L+=a[i];
	}
	
	int rmid,sum=0;
	for (int i=1;i<=n;++i){
		sum+=a[i];
		int tmp=L/2+(L%2);
//		printf("[debug]L/2=%lld\n",L/2);
		if (sum>=tmp){
			int r=sum;
			int l=sum-a[i];
			char c_=c[i];
			int tmp2=a[i];
			
//			printf("[debug]l=%lld r=%lld c_=%c i=%lld sum=%lld tmp=%lld\n",l,r,c_,i,sum,tmp);
			for (int j=n;j>=i;--j){
				a[j+2]=a[j];
				c[j+2]=c[j];
			}n+=2;
			a[i]=tmp-l;c[i]=c_;
			a[i+1]=tmp2%2;c[i+1]=c_;
			a[i+2]=r-tmp;c[i+2]=c_;
			rmid=i+1;
			break; 
		}
	}
//	printf("[debug]rmid=%lld\n",rmid);
//	for (int i=1;i<=n;++i){
//		cout<<a[i]<<' '<<c[i]<<endl;
//	}
	int la=0,ra=0,lid=1,rid=n;
	char lc,rc;
	while(lid<=rmid&&rid>=rmid){
//		printf("[debug]la=%lld ra=%lld | lc=%c rc=%c | lid=%lld rid=%lld L=%lld ans=%lld |\n",la,ra,lc,rc,lid,rid,L,ans);
		if (la==0){
			//la清完了
			la=a[lid];
			lc=c[lid];
			++lid; 
		}
		if (ra==0){
			ra=a[rid];
			rc=c[rid];
			--rid;
		}
//		printf("[debug]la=%lld ra=%lld | lc=%c rc=%c | lid=%lld rid=%lld L=%lld ans=%lld |\n",la,ra,lc,rc,lid,rid,L,ans);
		int minn=min(la,ra);
		//开始判断
		if (lc==rc){
			//回文段
			la-=minn;
			ra-=minn; 
		} 
		else {
			la-=minn;
			ra-=minn;
			ans+=minn;
			//不回文段 
		}
//		printf("[debug]la=%lld ra=%lld | lc=%c rc=%c | lid=%lld rid=%lld L=%lld ans=%lld |\n",la,ra,lc,rc,lid,rid,L,ans);
	}
	cout<<ans;
	return 0;
}
/*
3
2 a
2 b
1 c

2
2 a
3 a

6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

5
2 a
2 b
1 c
2 b
2 a

3
2 a
3 b
1 a

4
1 a
5 c
2 d
1 e

6
1 a
1 a
1 a
1 b
1 b
1 b

26
1 a
1 b
1 c
1 d
1 e
1 f
1 g
1 h
1 i
1 j
1 k
1 l
1 m
1 n
1 o
1 p
1 q
1 r
1 s
1 t
1 u
1 v
1 w
1 x
1 y
1 z
*/
