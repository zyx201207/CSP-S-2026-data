#include<bits/stdc++.h>
using namespace std;
long long n,u[200005],z,ln,rn;
char a[200005];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1; i<=n; i++)scanf("%lld%s",&u[i],&a[i]);
	int l=1,r=n; ln=u[1]; rn=u[n];
	while(r>l){
		if(ln>=rn){
			if(a[l]==a[r]){
				ln-=rn;
				r--;
				rn=u[r];
			}
			else{
				z+=rn;
				ln-=rn;
				r--;
				rn=u[r];
			}
		}
		else{
			if(a[l]==a[r]){
				rn-=ln;
				l++;
				ln=u[l];
			}
			else{
				z+=ln;
				rn-=ln;
				l++;
				ln=u[l];
			}
		}
		if(ln==0){
			l++;
			ln=u[l];
		}
		if(rn==0){
			r--;
			rn=u[r];
		}
	}
	printf("%lld",z);
	return 0;
}
