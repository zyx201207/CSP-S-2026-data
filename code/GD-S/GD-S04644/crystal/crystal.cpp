#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5 * 1e5 + 10;
long long n,m;
int a[MAXN];
int ch[MAXN];
long long pre[MAXN];
/*

最后一个小时
假解了，ccf我草泥马
再见了，致我5年的oi生涯
HuanL ORZ
worruonb
R.I.P
OwOfcen
2026 10 31
没心情复制//freopen了

保龄了估计
有舍才有得，你怎么知道现在选局部最优解就一定是全局最优解呢

 
A.F.O 
*/
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	
	for(int i = 1;i <= n;i ++){
		cin>>a[i];
		
	}
	sort(a+1,a+n+1);
	for(int i = 1;i <= n;i ++){
		ch[i] = a[i] - a[i-1];
		pre[i] = pre[i-1] + a[i];
		//cout<<ch[i]<<" "<<pre[i]<<'\n';
	}
	
	long long cnt = 0;
	for(int i = 1;i <= n;i ++){
		cnt += a[n] - a[i];
	}
	//cout<<cnt<<'\n';
	int l = 1,r = n;
	while(cnt > m && l+1 <= r){
		//cout<<l<<' '<<r<<'\n';
		long long lv = ch[l],lr = ch[r] * (r-l+1);
		//cout<<lv<<" "<<lr<<'\n';
		if(lv >= lr){
			cnt -= a[r] - a[l] + lv;
			l ++;
			
		}
		else{
			cnt -= lr;
			r --;
		}
	}
	if(cnt > m){
		cout<<1;
		return 0;
	}
	cout<<r - l + 1; 
}

