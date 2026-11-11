#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],mn=LONG_LONG_MAX,mx;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	long long t=2;
	map<long long,bool>mp;
	for(int i=1;i<=20;i++){
		mp[t]=true;
		t*=2;
	}
	bool fa=true,fb=true;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<mn)mn=a[i];        //te shu xing zhi A
		if(!mp[a[i]+1])fa=false;   //te shu xing zhi A
		if(a[i]!=i-1)fb=false;     //te shu xing zhi B
	}
	if(fa){//te shu xing zhi A
		cout<<mn;
		return 0;
	}
	if(fb){//te shu xing zhi B
		cout<<0;
		return 0;
	}
	long long jiange=n-m;
	long long l=1,r=jiange;
	bool di_yi_ci_xun_huan=true;
	for(int k=1;k<=m+1;k++){
//		cout<<"l="<<l<<' '<<"r="<<r<<":";////////////////////////////////////////ceshishuchu
		for(int i=1;i<=n;i++){
			if(i>=l&&i<=r){
				i=r+1;
			}
			if(r+1>n)break;
//			cout<<a[i]<<" ";             ////////////////////////////////////////ceshishuchu
			if(di_yi_ci_xun_huan)mx=a[i];
			else mx=(mx&a[i]);
		}
		l++;
		r++;
//		cout<<'\n';                      ////////////////////////////////////////ceshishuchu
	}
	cout<<mx;
	return 0;
}