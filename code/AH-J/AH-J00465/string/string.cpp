#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,num[200010],cnt,len;
char a[200010];
string s;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(ll i=1;i<=n;i++){
		cin>>num[i]>>a[i];
	}ll l=1,r=n;
	while(l<r){
		ll p=min(num[l],num[r]);
		if(a[l]!=a[r]) cnt+=p;
		num[l]-=p,num[r]-=p;
		if(num[l]==0) l++;
		if(num[r]==0) r--;
	}cout<<cnt;
    return 0;
}
