#include <bits/stdc++.h>
using namespace std;
int n;
long long a[200005],b[200005],ans;
char c[200005];
int main(){
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
		b[i]=a[i]+b[i-1];
	}
	long long p=1,q=b[n],i1=1,i2=n,mid_b=b[n]/2;
	while(p!=mid_b){
//		printf("p:%lld q:%lld i1:%lld i2:%lld\n",p,q,i1,i2);
		if(!(p>=b[i1-1]+1&&p<=b[i1])){
			i1++;
		}
		if(!(q>=b[i2-1]+1&&q<=b[i2])){
			i2--;
		}
		if(c[i1]!=c[i2]){
			ans++;
		}
		p++;
		q--;
	}
	cout<<ans;
	return 0;
}/*6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/
//Trick||Treat!
