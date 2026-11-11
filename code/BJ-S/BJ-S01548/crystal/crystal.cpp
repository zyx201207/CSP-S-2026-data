#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],c[500005],sum;
bool isa,isb;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=i)isa=true;
    }
    sort(a+1,a+n+1);
    for(long long i=2;i<=n;i++){
		b[i-1]=a[i]-a[i-1];
	}
	for(long long i=1;i<n;i++){
		if(b[i]!=b[1]){isb=true;break;}
	}
	for(long long i=1;i<=n;i++){
		c[i]=c[i-1]+a[i];
	}
	if(isa==0||isb==0){
		for(long long i=1;i<=n;i++){
			long long x=a[i]*i-c[i];
			if(x<=m)sum=max(sum,i);
		}
	}else{
		for(long long i=1;i<n;i++){
			for(long long j=n;j>=i;j--){
				long long x=a[j]*(j-i+1)-c[j-i+1];
				if(x<=m)sum=max(sum,j-i+1);
			}
		}
	}
	cout<<sum;
    return 0;
}
