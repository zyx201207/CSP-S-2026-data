#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+5; 
int n,m,su[N],ans,rq,qz[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>su[i];
	rq=0;
	sort(su+1,su+n+1);
	for(int i=1;i<=n;i++)qz[i]=qz[i-1]+su[i];
	for(int i=1;i<=n;i++){
		while(su[i]*(i-1-rq)-(qz[i-1]-qz[rq])>m&&rq<=n)rq++;
		ans=max(ans,i-rq);
	}
	cout<<ans;
	return 0;
}
/*
"C://Users//admin//Desktop//test.in.txt"
"C://Users//admin//Desktop//test.out.txt"
fc "C:\Users\admin\Desktop\test.out.txt" "C:\Users\admin\Desktop\test.ans.txt"	
开t1
n^2暴力是好写的 
我们先暴力枚举一下我们 确定的能量 然后贪心就好了
感觉可以按照能量值排序
然后双指针做
5 5
1 2 4 8 9
 
*/
