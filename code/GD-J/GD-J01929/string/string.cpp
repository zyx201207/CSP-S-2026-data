#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
using ll=long long;
ll a[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ll n;
	cin>>n;
	string s;
	ll len=0;
	ll t=1;
	ll y=1;
	string c;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(i!=1){
			t=__gcd(a[i],y);
		}
		y=a[i];
		cin>>c[i];
	//记录字符串的长度
	}
	for(ll i=1;i<=n;i++){
		a[i]/=t;
		len+=a[i];
		while(a[i]--){
			s+=c[i];
		}
	}
	string snew="";
	ll mid=(0+len)/2;//取中间值
	for(ll i=mid+1;i<len;i++){
		snew+=s[i];//把后面的拼接
	}
	ll cnt=0;//记录次数
	reverse(snew.begin(),snew.end());//翻转
	//cout<<snew<<'\n';
	//cout<<snew<<'\n';
	for(ll i=0;i<snew.size();i++){
		if(s[i]!=snew[i]){
			//cout<<i<<' '<<snew[i]<<" "<<'\n';
		    cnt++;//如果不相同 就更改
	}
	}
	cout<<cnt;
	return 0;
}
