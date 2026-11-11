#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;

long long n,m,a[N];
bool check_A=true;
/*
排序 双指针从后往前找
计算空缺的大小
空缺比m大就i--，存len，空缺变小 
否则就j-- 
*满分解 O(n) 
*/
long long cnt=0,maxlen=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(i>1&&a[i]!=a[i-1]) check_A=false;
	}
	sort(a+1,a+n+1);
	if(check_A){
		printf("%lld",n);
		return 0;
	}//15pts
	long long i,j;
	for(i=n,j=n;i>=j&&j>=1;j--){
		cnt+=(a[i]-a[j]);//增加量 
		if(cnt>m){
			maxlen=max(maxlen,i-j);//存长度 
			while(cnt>m){
				cnt-=((a[i]-a[i-1])*(i-j));//减掉i--之后的差值 
				i--;
			}
		}
	}
	if(i-j>maxlen) maxlen=i-j;//可能到最后没有保存长度 
	printf("%lld",maxlen);
	return 0;
}

//简单到爆（w 
/*
5 5
1 2 4 8 9
5 8
-3 -1 2 2 7
*/
