//准考证号：GZ-S00055 观山湖中学 胡峻豪 
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N=5e5+10;
ll n,m,a[N],x,b[N],s[N],s1[N],mx=INT_MIN,ans=0;

void xxxx(int k){
	s[k+1]=a[k+1]-a[k];
	if(m==0){
		return;
	}else if(s[k+1]!=0){
		m-=s[k+1];
		if(m<0)return;
		a[k]+=s[k+1];
		xxxx(1);
	}else if(s[k+1]==0){
		xxxx(k+1);
	} 
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=a[i]-a[i-1];
	}sort(a+1,a+1+n);
	xxxx(1);
	for(ll i=1;i<=n;i++){
		b[a[i]]++;
		ans=max(ans,b[a[i]]);
	}
	cout<<ans;
	return 0;
}
