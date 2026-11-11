#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long ans;
long long a[500010];
long long s[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		long long l=0,r=i+1;
		while(l+1<r){
			long long mid=(l+r)/2;
			if(a[i]*(i-mid+1)-(s[i]-s[mid-1])<=m)r=mid;
			else l=mid;
		}
		if(a[i]*(i-r+1)-(s[i]-s[r-1])<=m)ans=max(ans,i-r+1);
	}
	cout<<ans;
	return 0;
}//a数组二分 前缀和 
/*【题目描述】
小 R 有 n 颗能量水晶，其中第 i (1 ≤ i ≤ n) 颗的能量值为整数 ai。
小 R 想用其中若干颗能量水晶合成一颗大水晶，用于合成的水晶必须具有相同的
. .
以任选一颗水晶，将其能量值增加 1
能量值。小 R 希望参与合成的水晶尽可能多。他可以进行至多 m 次操作。每次操作可
；同一颗水晶可以被重复选择。
你需要帮助小 R 求出，进行至多 m 次操作后，他最多能用多少颗能量水晶合成一
颗大水晶。*/
//给定一个r，使a[r]*(r-l+1)-(a_r-a_{l-1})的值<=m，且r-l+1最大 
//考虑二分+前缀和实现O( 
