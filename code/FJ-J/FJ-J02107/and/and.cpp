#include<bits/stdc++.h>
using namespace std;
long long a[200005],m,n,sun,maxn;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n;
	for(int j=1;j<=n;j++){
		cin>>a[j];
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			sun=0;
			while(a[i]!=0){
				sun+=a[i]%2;
				a[i]/=2;
			}
			maxn=max(maxn,sun);
		}
	}else if(m==n){
		for(int i=1;i<=n;i++){
			sun=((a[i])^(sun));
		}
		while(sun!=0){
			maxn+=sun%2;
			sun/=2;
		}
	}else if(m=2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;i++){
				sun=0;
				int f=((a[i])^(a[j]));
				while(f!=0){
					sun+=f%2;
					f/=2;
				}
				maxn=max(maxn,sun);
			}
		}
	}else if(m=n-1){
		int k=0;
		for(int i=1;i<=n;i++){
			k=((k)^(a[i]));
		}
		for(int i=1;i<=n;i++){
			sun=0;
			k=((k)^(a[i]));
			while(k!=0){
					sun+=k%2;
					k/=2;
				}
				maxn=max(maxn,sun);
		}
	}
	cout<<maxn;
	return 0;
}
