#include"bits/stdc++.h"
using namespace std;
const int N=5e5+5;
typedef long long ll;
const ll M=1000000000000ll;
ll a[N],m,sum=0;
int n,mx=0,pos=1;
int main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    	cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		if(i>1)sum+=(a[i]-a[i-1])*(i-pos);
		while(sum>m&&pos<=i){
			sum-=a[i]-a[pos];
			++pos;
		} 
		mx=max(mx,i-pos+1);
	}
	cout<<mx; 
}

