/*

健忘的症状
这种赶春的人
该向左或向右

为什么这么简单
居然还出原题
有一个显然的贪心
那就是尽量选最高位的
因为往下的位再大也不会大于那个位
随便搞搞
复杂度 O(n)
*/
#include <bits/stdc++.h>
using namespace std;

const int N=2e5+10;
int n,m,a[N],ans;
vector<int> mp;

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];mp.push_back(i);
	}
	for(int k=30;~k;k--){
		vector<int> tmp(0);
		for(int i=0;i<mp.size();i++){
			if(a[mp[i]]&(1<<k)) tmp.push_back(mp[i]);
		}
		if(tmp.size()>=m){
			ans|=(1<<k);
			mp=tmp;
		}
	}
	cout<<ans;
	return 0;
}
