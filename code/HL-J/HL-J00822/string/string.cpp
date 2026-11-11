#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e5+200;
ll a1[N],a2[N],n,ans,sum1,sum2,k1=1,k2=1;
char c1[N],c2[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a1[i]>>c1[i];
		a2[n-i+1]=a1[i],c2[n-i+1]=c1[i];
	}
	while(k1<=n){
		if(c1[k1]!=c2[k2]){
			ans+=min(a1[k1]-sum1,a2[k2]-sum2);
		}
		int x=min(a1[k1]-sum1,a2[k2]-sum2);
		sum1+=x;
		sum2+=x;
		if(sum1>=a1[k1]){
			k1++;
			sum1-=a1[k1-1];
		}
		if(sum2>=a2[k2]){
			k2++;
			sum2-=a2[k2-1];
		}
	}
	cout<<ans/2;
	return 0;
}