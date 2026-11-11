#include <bits/stdc++.h>
using namespace std;
long long n,m,d,q;
long long w[1000005];
struct load{long long a;long long t;};
load l[1000005];
int main(){
freopen("subway.in","r",stdin);
freopen("subway.out","w",stdout);
cin>>n>>n>>m>>d>>q;
for(long long i=1;i<=m;i++){
    cin>>w[i];
}
for(long long i=1;i<=n;i++){
    long long k;
    cin>>k;
    for(long long j=1;j<=k;j++){
		cin>>l[i]
	}
}
return 0;
}
