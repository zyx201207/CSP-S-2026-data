#include <bits/stdc++.h>
using namespace std;
int a[200005];
bool cmp(int lzm,int mzl){
	return lzm>mzl;
}
int yu(string x,string y){
	int ans=0;
	for(long long i=min(x.size(),y.size())-1;i>=0;i--){
		if(x[i]=='1'&&y[i]=='1'){
			ans=ans+pow(2,i);
		}
	}
	return ans;
}
string zhuan(int l){
	string z,m;
	while(l!=0){
		if(l%2==1){
			z=z+'1';
			l/=2;
		}
		else{
			z=z+'0';
			l/=2;
		}
	}
	return z;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,M,mx=0;
	cin>>n>>M;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	mx=yu(zhuan(a[1]),zhuan(a[2]));
	for(int i=3;i<=M;i++){
		mx=yu(zhuan(mx),zhuan(a[i]));
	}
	cout<<mx;
	return 0;
}
