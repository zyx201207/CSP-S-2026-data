#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=4e5;
char c[N];
ll num[N],ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>num[i]>>c[i];
	ll l=1,r=n,lu=num[1],ru=num[n];
	while(l<r){
		ll f=!(c[l]==c[r]);
		if(lu>ru) ans+=ru*f,lu-=ru,r--,ru=num[r];
		else if(lu<ru) ans+=lu*f,ru-=lu,l++,lu=num[l];
		else ans+=lu*f,l++,r--,lu=num[l],ru=num[r];
	}
	cout<<ans;
	return 0;
} 
