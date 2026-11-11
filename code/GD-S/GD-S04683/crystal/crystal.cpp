#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;
#define ll long long
const ll Max=500014;
ll crystal[Max];
ll n,m;

ll f(ll i,ll j){
	 return crystal[j]-crystal[i];			//计算水晶i到水晶j的差值(i<j)
}

ll solve(){							//算法：滑动窗口(或双指针) 
	ll r=0,l=0;							//左右指针 
	ll cnt=0,res=0;						//当前操作数&水晶数量最大值
	while(r<n){
		r++;
		cnt+=f(r-1,r)*(r-l);	//cout<<"r->    "<<"cnt="<<cnt<<endl;
		while(cnt>m){
			l++;			
			cnt-=f(l,r);		//cout<<"l->    "<<"cnt="<<cnt<<endl;
		}
		res= res>r-l+1? res:r-l+1;
//		cout<<"r:"<<r<<" l:"<<l<<" cnt:"<<cnt<<" res:"<<res<<endl;
	}
	return res;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(ll i=0;i<n;i++) cin>>crystal[i];
	sort(crystal,crystal+n);
	cout<<solve();
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
