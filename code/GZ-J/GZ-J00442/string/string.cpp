//遵义市新蒲新区滨湖中学 金卓承 GZ-J00442 
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n,ans;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){
		ll x;
		char a;
		scanf("%lld %c",&x,&a);
		while(x--){
			s+=a;
		}
	}
	for(int i=0,j=s.size()-1;i<j;i++,j--){
		if(s[i]!=s[j]) ans++;
	}
	printf("%lld",ans);
	return 0;
}
