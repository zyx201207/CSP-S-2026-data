#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll =long long;
using pii = pair<int,int>;
const int N=2e5+9,M=4e5+9,inf=1e9+9;
const int mode=998244533;
ll a[N];//总和超过int
char c[N];

void solved(){
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	int l=1,r=n;
	ll cnt=0;
	while(l<r){
		char c1=c[l],c2=c[r];
		ll sum=min(a[l],a[r]);
		if(c1!=c2)cnt+=sum;
		a[l]-=sum,a[r]-=sum;
		if(a[l]==0)l++;
		if(a[r]==0)r--;
	}
	cout<<cnt;
}

int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	solved(); 
	return 0;
}
/*
思路：
因为回文串一定要配对，而配对是什么无所谓，所以只跟相对的元素有关
所以可以用双指针枚举扫描块
，块与块之间是怎么个位置不用管，我们只关心字符的相对位置
记得开ll 因为 每个位置会不一样
 O(n)
 空间 n*8 
 ok!
*/
