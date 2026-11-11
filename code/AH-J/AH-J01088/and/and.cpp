#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],maxn=-0x3f3f3f3f3f3f3f3f;
bool cmp(long long x,long long y){
    return x>y;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
        cin>>a[i];
	}
	if(m==2&&n<=10000){
        for(long long i=1;i<=n;i++){
            for(long long j=i+1;j<=n;j++){
                long long t=(a[i]&a[j]);
                maxn=max(maxn,t);
            }
        }
        cout<<maxn;
	}else{
        sort(a+1,a+n+1,cmp);
        cout<<a[m];	
	}
	return 0;
}
