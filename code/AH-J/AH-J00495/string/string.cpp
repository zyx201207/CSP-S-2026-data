#include <bits/stdc++.h>
using namespace std;
#define F std::ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
typedef unsigned long long ull;
int main(void){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	F;
	ll n,h[200005],i,j,cnt=0;
	char c[200005]{0};
	cin>>n;
	for(i=1,j=1;i<=n;++i){
		cin>>h[j]>>c[j];
		if(c[j]==c[j-1])h[j-1]+=h[j];
		else ++j;
	}
	n=j-1;
	for(i=1,j=n;i<j;){
		if(h[i]>h[j]){
			if(c[i]!=c[j])cnt+=h[j];
			h[i]-=h[j],--j;
		}else if(h[i]<h[j]){
			if(c[i]!=c[j])cnt+=h[i];
			h[j]-=h[i],++i;
		}else{
			if(c[i]!=c[j])cnt+=h[i];
			++i,--j;
		}
	}
	cout<<cnt<<endl;
	return 0;
}
