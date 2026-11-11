#include<bits/stdc++.h>
using namespace std;
#define ll long long 
//额哈哈
//我是CodingLoverRao29(1470495)
//我来打S力！
//神秘压缩包密码 `Oct31==Dec25?`
//不尔官方也爱玩梗吗 
ll n,m;
ll a[500005];
ll ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	//克雷斯托先生 
	ios::sync_with_stdio(0); cin.tie(0);
	cin>>n>>m;
	bool special_a=1,special_b=1;
	for(int i=1; i<=n; ++i){
		cin>>a[i];
		if(a[i]!=i)special_a=0;
		if(i>2){
			if(a[i]-a[i-1]!=a[i-1]-a[i-2])special_b=0;
		}
	}
	if(special_a){//特殊性质 a，看m撑得住几回 
		ll lun=0,tot=0;
		while(lun<=n&&tot<=m){//退出2方式：
			//1.爆n了，此时lun=n+1，-1是必须的
			//2.爆m了，此时lun个是不够的，需要-1 
			lun++;
			tot+=lun;
		}
		cout<<lun-1;
		return 0;
	}
	if(special_b){//特殊性质b，等差数列，大概同上 
		int cha=a[2]-a[1];
		ll lun=0,tot=0;
		while(lun<=n&&tot<=m&&tot>=0){
			lun++;
			tot+=lun*cha;
		}
		cout<<lun-1;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1; i<=n; ++i){//贪心暴力，9个点，45pts 
		ll m1=m;
		int j=i-1;
		ll res=1;
		while(m1>0&&j>0){
			if(m1>=(a[i]-a[j])){
				res++;
				m1-=(a[i]-a[j]);
			}
			j--;
		}
		ans=max(ans,res);
	}
	cout<<ans;
	return 0;
}
/*
emm
你一共可以加m个1
需要让更多的数相等
......
停停停等一下？
什么叫m<=10^18
好吧
由于平衡值肯定是a中的一个
所以我们可以……
算了，大概可以拿75 
*/


































//

