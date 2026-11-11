#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
ll n,m,a[N],ma[N],cnt,ans,xia;//ma£º1~iµÄ²îÖµ 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	ma[0]=0;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(i>=2){
			ll cha=a[i]-a[i-1];
			ma[i]=cha*(i-1)+ma[i-1];
		}else{
			ma[1]=0;
		}
		//cout<<ma[i]<<endl;
		if(ma[i]<=m){
			if(ma[i]>=ans){
				ans=ma[i];
				xia=i;
			}
		}
	} 
	cout<<xia;
	return 0;
}
