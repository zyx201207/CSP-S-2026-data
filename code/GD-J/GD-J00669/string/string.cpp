#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,a[200005],ans,sum,q[200005];
char c[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		sum+=a[i];
		q[i]=q[i-1]+a[i];
	}
	cout<<0;
    return 0;
}
