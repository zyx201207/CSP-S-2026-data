//GZ-J00458 邓可为 兴义市弘毅中学 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2*10e5+1;
ll n,a[N],ans;
char b[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld %c",&a[i],&b[i]);
		getchar();
	}	
	ll i=1,j=n;
	while(i<=j){
		if(a[i]>a[j]){
			a[i] -= a[j];
			if(b[i]!=b[j])
				ans += a[j];
			j--;
		}
		else{
			a[j] -= a[i];
			if(b[i]!=b[j])
				ans += a[i];
			i++;
		}
	}
	printf("%lld\n",ans);
	return 0;
} 
