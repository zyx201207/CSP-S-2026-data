#include<bits/stdc++.h>
#define int long long
#define FOR(i,a,b) for(int i=(a);i<=(int)(b);i++)
using namespace std;
int n,m;
int a[500001];
int b[500001];//差分
int c[500001];//前缀和 
int sum;//目前双指针区域所需能量，只有小于m时才能记录ans 
int ans;//双指针之间区域的最大值 
int head,tail;//双指针 
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	FOR(i,1,n) cin>>a[i];
	sort(a+1,a+1+n);
	FOR(i,2,n) b[i]=a[i]-a[i-1];
	FOR(i,1,n) c[i]=c[i-1]+b[i];
	head=1;
	tail=1;
	while(head<=n){
		/*
		1.head和tail开头都在1位置
		2.开始循环，检查sum值，是否小于等于m
			2.1如果小于等于m，那么更新ans，取最大区间值，将head推进一位
				2.1.1推进后，将sum值加上(head-tail)*b[head]
			2.2超过了就将tail前进一位
				2.2.1将sum值减去c[head]-c[tail-1]
				2.2.1.1sum还是超了就回到2.2
				2.2.1.2sum值没超就回到2 
				
		*/
		if(sum<=m){
			ans=max(ans,head-tail+1);
			head++;
			sum+=(head-tail)*b[head];
		} 
		else {
			tail++;
			sum-=(c[head]-c[tail-1]);
		}
	}
	cout<<ans;
	return 0;
}
/*
排序 
1.二分答案？ 
2.双指针？ 
54min
*/
