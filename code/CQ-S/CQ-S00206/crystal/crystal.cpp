#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long m,a[500050],qzh[500050];
int b_s_(int x){
	int l=1,r=x;
	while(l<r){
		int mid=(l+r)/2;
		long long w=a[x]*(x-mid+1)-(qzh[x]-qzh[mid-1]);
		if(w<=m)r=mid;
		else l=mid+1;
	}
	return l;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		qzh[i]=qzh[i-1]+a[i];
//		cerr<<qzh[i]<<' ';
	}
	for(int i=1;i<=n;i++){
		int w=b_s_(i);
//		cerr<<i<<' '<<w<<'\n';
		ans=max(ans,i-w+1);
	}
	cout<<ans<<'\n';









	return 0;
}

/*

可以二分答案吗

不用，对于每个 ai 进行判定

二分答案，前缀和一下

简单题 

音乐的水晶

有负数啊，处理一下

样例 2 可以 1~4 全都提升到 2

8 ops

样例不满，不要写挂！ 

5 5
1 2 4 8 9


 5 8
-3 -1 2 2 7


 5 8
 7 -1 2 2 -3
crystal.exe < crystal1.in > crystal1.out
crystal.exe < crystal2.in > crystal2.out
crystal.exe < crystal3.in > crystal3.out
crystal.exe < crystal4.in > crystal4.out
fc crystal1.ans crystal1.out
fc crystal2.ans crystal2.out
fc crystal3.ans crystal3.out
fc crystal4.ans crystal4.out

D:\CQ-S00206>fc crystal3.ans crystal3.out
正在比较文件 crystal3.ans 和 CRYSTAL3.OUT
***** crystal3.ans
3845
***** CRYSTAL3.OUT
5000
*****


D:\CQ-S00206>fc crystal4.ans crystal4.out
正在比较文件 crystal4.ans 和 CRYSTAL4.OUT
***** crystal4.ans
315275
***** CRYSTAL4.OUT
500000
*****


D:\CQ-S00206>crystal.exe < crystal1.in > crystal1.out

D:\CQ-S00206>crystal.exe < crystal2.in > crystal2.out

D:\CQ-S00206>crystal.exe < crystal3.in > crystal3.out

D:\CQ-S00206>crystal.exe < crystal4.in > crystal4.out

D:\CQ-S00206>fc crystal1.ans crystal1.out
正在比较文件 crystal1.ans 和 CRYSTAL1.OUT
FC: 找不到差异


D:\CQ-S00206>fc crystal2.ans crystal2.out
正在比较文件 crystal2.ans 和 CRYSTAL2.OUT
FC: 找不到差异


D:\CQ-S00206>fc crystal3.ans crystal3.out
正在比较文件 crystal3.ans 和 CRYSTAL3.OUT
FC: 找不到差异


D:\CQ-S00206>fc crystal4.ans crystal4.out
正在比较文件 crystal4.ans 和 CRYSTAL4.OUT
FC: 找不到差异
*/

