//GZ-J00511 张俊熙 兴义市弘毅中学
#include<iostream>
#include<cmath>
#include<algorithm>
#include<map>
#define ll long long
using namespace std;
ll n,b[200005],sum,ans,a,c;
string s;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++){
		scanf("%lld %c",&a,&c);
		for(ll j=1;j<=a;j++){
			s+=c;
		}
	}for(ll i=0,j=s.size()-1;i<j;i++,j--){
		if(s[i]!=s[j]) ans++;
	}printf("%lld",ans);
	
	return 0;
}
