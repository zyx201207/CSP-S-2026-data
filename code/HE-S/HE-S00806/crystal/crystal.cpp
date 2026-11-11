#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,mx;
long long a[N],s[N],ansn;
long long ans,cut;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    scanf("%lld %lld",&n,&m);
    for(int i=1;i<=n;++i) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	mx=a[n];
	for(int i=n;i>=1;--i) s[n-i+1]=s[n-i]+mx-a[i];
	int j=1;
	for(int i=n;i>=1;--i){
		cut+=(mx-a[i])*(j-n+i);
		for(;j<=n;++j){
			if(s[j]-cut<=m){
				++ans;
				cut+=mx-a[i];
			}
			else{
				break;
			}
		}
		cut-=(mx-a[i])*(j-n+i-1);
		ansn=max(ansn,ans);
		--ans;
	}
	printf("%lld\n",ansn);
//	cout<<clock();
	return 0;
}
// q.7
//~l2
