#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=2e5+10;
LL n;string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	LL ans=0;
	for(LL i=0;i<n;i++){
		LL x;char c;
		cin>>x>>c;ans+=x;
		while(x--){
			s=s+c;
		}
	}
	LL z,y;
	if(ans%2==1){
		z=(ans+1)/2-1;
		y=z;
	}else{
		z=ans/2-1;
		y=ans/2;
	}
	ans=0;
	while(z>=0){
		if(s[z]!=s[y]) ans++;
		z--;y++;
	}
	cout<<ans;		
	return 0;
}
