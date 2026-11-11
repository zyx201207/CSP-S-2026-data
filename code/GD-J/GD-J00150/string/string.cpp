#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,a[N],len=0,ans=0;
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		len+=a[i];
		a[i]+=a[i-1];
		while(c[i]<'a'||c[i]>'z') c[i]=getchar();
	}
	int L=1,posL=1,R=len,posR=n;
	/*
	L：左指针（在一整个字符串内）
	posL：左指针所在的段的编号
	R,posR 同理 
	*/ 
	while(L<=R&&posL<=posR){
		int lesL=a[posL]-L+1,lesR=R-a[posR-1];
		//lesL 指当前左指针所在的段还有多少个没有访问过，lesR 同理 
		/*
		printf("debug LR:%lld %lld\n",L,R); 
		printf("debug pos:%lld %lld\n",posL,posR); 
		printf("debug les:%lld %lld\n",lesL,lesR);
		*/
		if(lesL<lesR){
			if(c[posL]!=c[posR]) ans+=lesL;
			L+=lesL,posL++;
			R-=lesL;
		}
		else if(lesR<lesL){
			if(c[posL]!=c[posR]) ans+=lesR;
			R-=lesR,posR--;
			L+=lesR;
		}
		else if(lesL==lesR){
			if(c[posL]!=c[posR]) ans+=lesL;
			L+=lesL,posL++;
			R-=lesL,posR--;
		}
		//左指针右指针变动的一样，所以指向的点对称 
	}
	printf("%lld",ans);
	return 0;
}
/*
考虑双指针，当指针两端字符不同时，必须修改一个，所以答案加一
注意到 a 到 1e9，n 到 2e5，字符串长度非常大会爆 
稍微优化一下

时间复杂度：O(n)
难度：orange ~ yellow 
*/
