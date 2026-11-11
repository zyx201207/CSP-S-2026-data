#include<bits/stdc++.h>
using namespace std;
long long c,T,n,d,a[2000005];
bool ff(int x,int y){
	if(a[x]+d>=a[y]) return false;
	int y2=0;
	for(int i=x+1;i<=y;i++){
		if(a[i]-a[i-1]>d) return false;
	}int aaaa=x;
	while(aaaa<y){
		for(int i=aaaa+1;i<=y;i++){
			if(aaaa+d>a[i]){
				aaaa=a[i-1];
				y2++;
				break;
			}
		}
	}return true;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;
		long long sum=0;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}if(a[2]-a[1]==a[n]-a[n-1]){
			if(a[2]-a[1]>d) cout<<"0\n";
			else cout<<n-3<<"\n";
		}else if(n<=5000){
			for(int i=1;i<n;i++){
				for(int j=i+1;j<=n;j++){
					if(ff(i,j)){
						sum++;
					}
				}
			}cout<<sum<<"\n";
		}
	}
	return 0;
}
