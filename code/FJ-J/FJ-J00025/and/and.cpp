#include<bits/stdc++.h>
using namespace std;
bool f[200005][33];
int n,m;
long long a[200005],ans;
void in(int x){
	for(long long i=0;i<30ll;i++){
		f[x][i]=(a[x]&(1ll<<i));
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		in(i);
	}
	vector<int>t,k;
	for(int i=1;i<=n;i++)t.push_back(i);
	for(long long i=29;i>=0;i--){
		int sum=0;
		for(int j:t){
			if(f[j][i]){
				sum++;
				k.push_back(j);
			}
		}
		if(sum>=m){
			ans+=(1ll<<i);
			t.swap(k);
		}
		k.clear();
	}
	cout<<ans;
	return 0;
}/*
T3看到按位与可以想到二进制拆分，
将所有数字加入vector，
i从29到0，
每次遍历一遍vector，看其中第i位是1的数是否有m个，
是的话就将所有第i位不是一的去除，将ans+=(1ll<<i);
否则不操作
具体见代码（实现方式不同，但思路一致）
应该是O(30n) 
//freopen
feropen
freopen("and.out","r",stdin);
freopen("and.ans","w",stdout);
freopen("and.in","r",stdin);
CCF CCF CCF CCF CCF CCF CCF CCF CCF CCF 
I AK CSP
(认真诈骗ing)
*/
