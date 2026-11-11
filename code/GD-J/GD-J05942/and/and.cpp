#include<bits/stdc++.h>
using namespace std;
long long n,m,a[20000005],maxx=-1,hb=-1;
unsigned long long ans=-1;
set<long long>b[64];
void f(long long i){
	for(long long j=i;j>0;)b[(j&-j)].insert(i),j-=(j&-j);
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++)cin>>a[i],f(a[i]),maxx=max(maxx,a[i]);
    for(long long i=maxx;i>0;)hb=(hb>(i&-i)?hb:(i&-i)),i-=(i&-i);
    for(long long i=hb;i>=0;i--)if(b[i].size()>=m){
		hb=i;
		break;
	}
	for(set<long long >::iterator i=b[hb].begin();i!=b[hb].end();i++)ans&=*i;
	cout<<ans;
    return 0;
}

