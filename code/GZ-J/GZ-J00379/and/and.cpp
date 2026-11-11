//GZ-J00379 兴义市弘毅中学 刘俊池 
#include <bits/stdc++.h>
using namespace std;
bool pd;
long long n,a[200009],m,zc,zd=-1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=0;i<n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=(1<<n);i++){
		vector<long long> v;
		pd=0;
		for(int j=0;j<n;j++){
			if(i&(1<<j)){
				v.push_back(a[j]);
				if(pd==0){
					zc=a[j];
					pd=1;
				}else{
					zc&=a[j];
				}
			}
		}
		if(v.size()==m){
			if(zc>zd){
				zd=zc;
			}
		}
	}
	printf("%lld\n",zd);
	return 0;
} 
