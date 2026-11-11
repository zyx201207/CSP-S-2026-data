#include<bits/stdc++.h>
using namespace std;
long long a[1000001];
long long c[1000001];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    c[0]=0;
    a[0]=0;
    for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
			long long f=0;
			long long t=0;
    for(long long i=1;i<=n;i++){
			for(long long y=2;y<=n;y++){
				for(long long z=1;z<y;z++){
					f++;
					c[f]=(a[y]&a[z]);
				}
				
			}
			for(long long k=1;k<=f;k++){
				c[k]=max(c[k-1],c[k]);
			}
		if(m==1){
			a[i]=max(a[i],a[i-1]);
			t++;
		}
	}
	if(m==1){
		cout<<a[t];
	}
	cout<<c[f];
    return 0;
}
