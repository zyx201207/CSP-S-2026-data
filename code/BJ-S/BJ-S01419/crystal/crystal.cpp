/*
crystal

开long long

暴力 O(N^2)

从（1）开始，变为（1，2，3，……，n）
若操作次数过多，更新答案，去掉前面的直至能加入后一个
  节约计算时间

最坏O(N^2)
最好O(N)

*/
#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005],ans=1,spent=0,len=1;
queue<long long> q;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	q.push(a[1]);
	for(int i=2;i<=n;i++){
		if(spent+len*(a[i]-a[i-1])>m){
			ans=max(ans,len);
			while(spent+len*(a[i]-a[i-1])>m){
				spent=spent-a[i-1]+q.front();
				q.pop();
				len--;
			}
		}
		spent+=len*(a[i]-a[i-1]);
		len++;
		q.push(a[i]);
	}
	ans=max(ans,len);
	cout<<ans;
	return 0;
}
