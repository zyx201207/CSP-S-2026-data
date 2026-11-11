#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll n,l,r,sum,tsum,s[200005],li,ri,mn;
struct s{
	ll a;
	char c;
}b[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>b[i].a>>b[i].c,r+=b[i].a,s[i]=s[i-1]+b[i].a;
	ll li=1,ri=n,r=s[n];
	while(l<r&&li<ri){
		mn=min(s[li]-l,r-s[ri-1]);
		if(b[li].c!=b[ri].c)sum+=mn;
		l+=mn,r-=mn;
		while(l>=s[li])li++;
		while(r<=s[ri-1])ri--;
	}
	cout<<sum;
	return 0;
}
